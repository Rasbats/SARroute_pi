/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  SARroute Plugin
 * Author:   David Register, Mike Rossiter
 *
 ***************************************************************************
 *   Copyright (C) 2010 by David S. Register   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.             *
 ***************************************************************************
 */

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include <wx/glcanvas.h>
#endif  // precompiled headers

#include <wx/fileconf.h>
#include <wx/stdpaths.h>

#include "ocpn_plugin.h"

#include "SARroute_pi.h"
#include "SARrouteUIDialogBase.h"
#include "SARrouteUIDialog.h"

// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin *create_pi(void *ppimgr) {
  return new SARroute_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin *p) { delete p; }

//---------------------------------------------------------------------------------------------------------
//
//    SARroute PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "icons.h"

//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------

SARroute_pi::SARroute_pi(void *ppimgr) : opencpn_plugin_118(ppimgr) {
  // Create the PlugIn icons
  initialize_images();

  wxFileName fn;

  auto path = GetPluginDataDir("SARroute_pi");
  fn.SetPath(path);
  fn.AppendDir("data");
  fn.SetFullName("SARroute_panel_icon.png");

  path = fn.GetFullPath();

  wxInitAllImageHandlers();

  wxLogDebug(wxString("Using icon path: ") + path);
  if (!wxImage::CanRead(path)) {
    wxLogDebug("Initiating image handlers.");
    wxInitAllImageHandlers();
  }
  wxImage panelIcon(path);
  if (panelIcon.IsOk())
    m_panelBitmap = wxBitmap(panelIcon);
  else
    wxLogWarning("SARroute panel icon has NOT been loaded");

  m_bShowSARroute = false;
}

SARroute_pi::~SARroute_pi(void) {
  delete _img_SARroute_pi;
  delete _img_SARroute;
}

int SARroute_pi::Init(void) {
  AddLocaleCatalog(_T("opencpn-SARroute_pi"));

  // Set some default private member parameters
  m_SARroute_dialog_x = 0;
  m_SARroute_dialog_y = 0;
  m_SARroute_dialog_sx = 200;
  m_SARroute_dialog_sy = 400;
  m_pSARrouteDialog = NULL;
  m_pSARrouteOverlayFactory = NULL;
  m_bSARrouteShowIcon = true;

  ::wxDisplaySize(&m_display_width, &m_display_height);

  m_pconfig = GetOCPNConfigObject();

  //    And load the configuration items
  LoadConfig();

  // Get a pointer to the opencpn display canvas, to use as a parent for the
  // SARroute dialog
  m_parent_window = GetOCPNCanvasWindow();

  wxMenu dummy_menu;
  m_position_menu_id = AddCanvasContextMenuItem(
      new wxMenuItem(&dummy_menu, -1, _("Delete Tidal Current Station")), this);
  SetCanvasContextMenuItemViz(m_position_menu_id, true);

  //    This PlugIn needs a toolbar icon, so request its insertion if enabled
  //    locally
  if (m_bSARrouteShowIcon)
#ifdef ocpnUSE_SVG
    m_leftclick_tool_id =
        InsertPlugInToolSVG(_T("SARroute"), _svg_SARroute, _svg_SARroute,
                            _svg_SARroute_toggled, wxITEM_CHECK, _("SARroute"),
                            _T(""), NULL, SARroute_TOOL_POSITION, 0, this);
#else
    m_leftclick_tool_id = InsertPlugInTool(
        _T(""), _img_SARroute, _img_SARroute, wxITEM_CHECK, _("SARroute"), _T(""),
        NULL, SARroute_TOOL_POSITION, 0, this);
#endif

  return (WANTS_OVERLAY_CALLBACK | WANTS_OPENGL_OVERLAY_CALLBACK |
          WANTS_NMEA_SENTENCES |
          WANTS_TOOLBAR_CALLBACK | WANTS_CURSOR_LATLON | INSTALLS_TOOLBAR_TOOL |
          WANTS_CONFIG | WANTS_ONPAINT_VIEWPORT | WANTS_PLUGIN_MESSAGING);
}

bool SARroute_pi::DeInit(void) {
  if (m_pSARrouteDialog) {
    m_pSARrouteDialog->Close();
    delete m_pSARrouteDialog;
    m_pSARrouteDialog = NULL;
  }

  delete m_pSARrouteOverlayFactory;
  m_pSARrouteOverlayFactory = NULL;

  return true;
}

int SARroute_pi::GetAPIVersionMajor() { return atoi(API_VERSION); }

int SARroute_pi::GetAPIVersionMinor() {
  std::string v(API_VERSION);
  size_t dotpos = v.find('.');
  return atoi(v.substr(dotpos + 1).c_str());
}

int SARroute_pi::GetPlugInVersionMajor() { return PLUGIN_VERSION_MAJOR; }

int SARroute_pi::GetPlugInVersionMinor() { return PLUGIN_VERSION_MINOR; }

wxBitmap *SARroute_pi::GetPlugInBitmap() { return &m_panelBitmap; }

wxString SARroute_pi::GetCommonName() { return PLUGIN_API_NAME; }

wxString SARroute_pi::GetShortDescription() { return PKG_SUMMARY; }

wxString SARroute_pi::GetLongDescription() { return PKG_DESCRIPTION; }

void SARroute_pi::SetDefaults(void) {}

int SARroute_pi::GetToolbarToolCount(void) { return 1; }

void SARroute_pi::OnToolbarToolCallback(int id) {
  if (!m_pSARrouteDialog) {
    m_pSARrouteDialog = new SARrouteUIDialog(m_parent_window, this);
    wxPoint p = wxPoint(m_SARroute_dialog_x, m_SARroute_dialog_y);
    m_pSARrouteDialog->pPlugIn = this;
    m_pSARrouteDialog->Move(0,
                           0);  // workaround for gtk autocentre dialog behavior
    m_pSARrouteDialog->Move(p);

    // Create the drawing factory
    m_pSARrouteOverlayFactory = new SARrouteOverlayFactory(*m_pSARrouteDialog);
    m_pSARrouteOverlayFactory->SetParentSize(m_display_width, m_display_height);
  }

  // Qualify the SARroute dialog position
  bool b_reset_pos = false;

#ifdef __WXMSW__
  //  Support MultiMonitor setups which an allow negative window positions.
  //  If the requested window does not intersect any installed monitor,
  //  then default to simple primary monitor positioning.
  RECT frame_title_rect;
  frame_title_rect.left = m_SARroute_dialog_x;
  frame_title_rect.top = m_SARroute_dialog_y;
  frame_title_rect.right = m_SARroute_dialog_x + m_SARroute_dialog_sx;
  frame_title_rect.bottom = m_SARroute_dialog_y + 30;

  if (NULL == MonitorFromRect(&frame_title_rect, MONITOR_DEFAULTTONULL))
    b_reset_pos = true;
#else
  //    Make sure drag bar (title bar) of window on Client Area of screen, with
  //    a little slop...
  wxRect window_title_rect;  // conservative estimate
  window_title_rect.x = m_SARroute_dialog_x;
  window_title_rect.y = m_SARroute_dialog_y;
  window_title_rect.width = m_SARroute_dialog_sx;
  window_title_rect.height = 30;

  wxRect ClientRect = wxGetClientDisplayRect();
  ClientRect.Deflate(
      60, 60);  // Prevent the new window from being too close to the edge
  if (!ClientRect.Intersects(window_title_rect)) b_reset_pos = true;

#endif

  if (b_reset_pos) {
    m_SARroute_dialog_x = 20;
    m_SARroute_dialog_y = 170;
    m_SARroute_dialog_sx = 300;
    m_SARroute_dialog_sy = 540;
  }

  // Toggle SARroute overlay display
  m_bShowSARroute = !m_bShowSARroute;

  //    Toggle dialog?
  if (m_bShowSARroute) {
    m_pSARrouteDialog->Show();
  } else {
    m_pSARrouteDialog->Hide();
  }

  // Toggle is handled by the toolbar but we must keep plugin manager b_toggle
  // updated to actual status to ensure correct status upon toolbar rebuild
  SetToolbarItemState(m_leftclick_tool_id, m_bShowSARroute);
  // SetCanvasContextMenuItemViz(m_position_menu_id, true);

  RequestRefresh(m_parent_window);  // refresh main window
}

void SARroute_pi::OnSARrouteDialogClose() {
  m_bShowSARroute = false;
  SetToolbarItemState(m_leftclick_tool_id, m_bShowSARroute);
  SetCanvasContextMenuItemViz(m_position_menu_id, m_bShowSARroute);

  m_pSARrouteDialog->Hide();

  SaveConfig();

  RequestRefresh(m_parent_window);  // refresh main window
}

wxString SARroute_pi::StandardPath() {
  wxString stdPath(*GetpPrivateApplicationDataLocation());
  wxString s = wxFileName::GetPathSeparator();

  stdPath += s + "SAR";
  if (!wxDirExists(stdPath)) wxMkdir(stdPath);
  stdPath = stdPath + s + "files";
  if (!wxDirExists(stdPath)) wxMkdir(stdPath);

  stdPath += s;
  return stdPath;
}

bool SARroute_pi::RenderOverlay(wxDC &dc, PlugIn_ViewPort *vp) {
  if (!m_pSARrouteDialog || !m_pSARrouteDialog->IsShown() ||
      !m_pSARrouteOverlayFactory)
    return false;

  if (m_pSARrouteDialog) {
    //m_pSARrouteDialog->OnCursor();
    m_pSARrouteDialog->SetViewPort(vp);
    m_pSARrouteDialog->MakeBoxPoints();
  }

  piDC pidc(dc);

  m_pSARrouteOverlayFactory->RenderOverlay(pidc, *vp);
  return true;
}

bool SARroute_pi::RenderGLOverlay(wxGLContext *pcontext, PlugIn_ViewPort *vp) {
  if (!m_pSARrouteDialog || !m_pSARrouteDialog->IsShown() ||
      !m_pSARrouteOverlayFactory)
    return false;

  if (m_pSARrouteDialog) {
    //m_pSARrouteDialog->OnCursor();
    m_pSARrouteDialog->SetViewPort(vp);
    m_pSARrouteDialog->MakeBoxPoints();
  }

  piDC piDC;
  glEnable(GL_BLEND);
  piDC.SetVP(vp);

  m_pSARrouteOverlayFactory->RenderOverlay(piDC, *vp);
  return true;
}

void SARroute_pi::SetCursorLatLon(double lat, double lon) {
  //if (m_pSARrouteDialog) m_pSARrouteDialog->SetCursorLatLon(lat, lon);

  m_cursor_lat = lat;
  m_cursor_lon = lon;
}

void SARroute_pi::SetPositionFix(PlugIn_Position_Fix &pfix) {
  m_ship_lon = pfix.Lon;
  m_ship_lat = pfix.Lat;
  // std::cout<<"Ship--> Lat: "<<m_ship_lat<<" Lon: "<<m_ship_lon<<std::endl;
  //}
}
bool SARroute_pi::LoadConfig(void) {
  wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

  if (!pConf) return false;

  pConf->SetPath(_T( "/PlugIns/SARroute" ));

  m_CopyFolderSelected = pConf->Read(_T( "SARrouteFolder" ));

  if (m_CopyFolderSelected == wxEmptyString) {
    wxString g_SData_Locn = *GetpSharedDataLocation();
    // Establish location of Tide and Current data
    pTC_Dir = new wxString(_T("tcdata"));
    pTC_Dir->Prepend(g_SData_Locn);

    m_CopyFolderSelected = *pTC_Dir;
  }

  m_SARroute_dialog_sx = pConf->Read(_T( "SARrouteDialogSizeX" ), 300L);
  m_SARroute_dialog_sy = pConf->Read(_T( "SARrouteDialogSizeY" ), 540L);
  m_SARroute_dialog_x = pConf->Read(_T( "SARrouteDialogPosX" ), 20L);
  m_SARroute_dialog_y = pConf->Read(_T( "SARrouteDialogPosY" ), 170L);

  return true;
}

bool SARroute_pi::SaveConfig(void) {
  wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

  if (!pConf) return false;

  pConf->SetPath(_T( "/PlugIns/SARroute" ));

  pConf->Write(_T( "SARrouteFolder" ), m_CopyFolderSelected);

  pConf->Write(_T( "SARrouteDialogSizeX" ), m_SARroute_dialog_sx);
  pConf->Write(_T( "SARrouteDialogSizeY" ), m_SARroute_dialog_sy);
  pConf->Write(_T( "SARrouteDialogPosX" ), m_SARroute_dialog_x);
  pConf->Write(_T( "SARrouteDialogPosY" ), m_SARroute_dialog_y);

  return true;
}

void SARroute_pi::SetColorScheme(PI_ColorScheme cs) {
  DimeWindow(m_pSARrouteDialog);
}
/*
void SARroute_pi::OnContextMenuItemCallback(int id)
{

        if (!m_pSARrouteDialog)
                return;

        if (id == m_position_menu_id) {

                m_cursor_lat = GetCursorLat();
                m_cursor_lon = GetCursorLon();

                m_pSARrouteDialog->OnContextMenu(m_cursor_lat, m_cursor_lon);
        }
}
*/
void SARroute_pi::OnContextMenuItemCallback(int id) {
  if (!m_pSARrouteDialog) return;

  if (id == m_position_menu_id) {
    m_cursor_lat = GetCursorLat();
    m_cursor_lon = GetCursorLon();
  }
}

bool SARroute_pi::MouseEventHook(wxMouseEvent &event) {
 // if (!m_pSARrouteDialog) return false;
/*
  if (event.LeftDown()) {
    //wxMessageBox("here");
    if (m_pSARrouteDialog) {
      m_cursor_lat = GetCursorLat();
      m_cursor_lon = GetCursorLon();
      wxString lat = wxString::Format("%f", m_cursor_lat);
      wxString lon = wxString::Format("%f", m_cursor_lon);

      m_pSARrouteDialog->m_Lat1->SetValue(lat);
      m_pSARrouteDialog->m_Lon1->SetValue(lon);
    }
    
  }
  */
  return true;
}

void SARroute_pi::SetNMEASentence(wxString &sentence) {
  if (NULL != m_pSARrouteDialog) {
    m_pSARrouteDialog->SetNMEAMessage(sentence);
  }
}