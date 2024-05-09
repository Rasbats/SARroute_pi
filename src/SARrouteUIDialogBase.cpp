///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "SARrouteUIDialogBase.h"

///////////////////////////////////////////////////////////////////////////

SARrouteUIDialogBase::SARrouteUIDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_notebook1->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	m_panelRoutes = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	m_treeCtrlRoutes = new wxTreeCtrl( m_panelRoutes, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_LINES_AT_ROOT|wxTR_MULTIPLE );
	bSizer7->Add( m_treeCtrlRoutes, 1, wxALL|wxEXPAND, 5 );


	m_panelRoutes->SetSizer( bSizer7 );
	m_panelRoutes->Layout();
	bSizer7->Fit( m_panelRoutes );
	m_notebook1->AddPage( m_panelRoutes, _("         Routes       "), false );
	m_panelObjects = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_panelObjects, wxID_ANY, _("Editor/Testing") ), wxHORIZONTAL );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_buttonAddTestItems = new wxButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Add test items"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAddTestItems->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );
	m_buttonAddTestItems->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_buttonAddTestItems->SetBackgroundColour( wxColour( 255, 0, 0 ) );

	fgSizer2->Add( m_buttonAddTestItems, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );

	wxArrayString m_choiceSchemaChoices;
	m_choiceSchema = new wxChoice( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceSchemaChoices, 0 );
	m_choiceSchema->SetSelection( 0 );
	fgSizer2->Add( m_choiceSchema, 0, wxALL, 5 );

	m_bLoadRTZ = new wxButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Load RTZ"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_bLoadRTZ, 0, wxALL, 5 );

	m_staticline3 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline3, 0, wxEXPAND | wxALL, 5 );

	m_staticline4 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );

	m_staticline5 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline5, 0, wxEXPAND | wxALL, 5 );

	m_staticline6 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline6, 0, wxEXPAND | wxALL, 5 );

	m_staticline7 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline7, 0, wxEXPAND | wxALL, 5 );

	m_staticline8 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline8, 0, wxEXPAND | wxALL, 5 );

	m_buttonAttach = new wxButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Index"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAttach->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	fgSizer2->Add( m_buttonAttach, 0, wxALL, 5 );

	m_buttonAttach1 = new wxButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Range"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAttach1->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	fgSizer2->Add( m_buttonAttach1, 0, wxALL, 5 );

	m_buttonAttach2 = new wxButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Direction"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAttach2->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	fgSizer2->Add( m_buttonAttach2, 0, wxALL, 5 );

	m_staticline10 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline10, 0, wxEXPAND | wxALL, 5 );

	m_staticline11 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline11, 0, wxEXPAND | wxALL, 5 );

	m_staticline12 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline12, 0, wxEXPAND | wxALL, 5 );

	m_staticline13 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline13, 0, wxEXPAND | wxALL, 5 );

	m_staticline14 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline14, 0, wxEXPAND | wxALL, 5 );

	m_staticline15 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline15, 0, wxEXPAND | wxALL, 5 );

	m_staticline16 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline16, 0, wxEXPAND | wxALL, 5 );

	m_staticline17 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline17, 0, wxEXPAND | wxALL, 5 );

	m_staticline18 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline18, 0, wxEXPAND | wxALL, 5 );

	m_staticline20 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline20, 0, wxEXPAND | wxALL, 5 );

	m_staticline21 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline21, 0, wxEXPAND | wxALL, 5 );

	m_buttonSave = new wxButton( sbSizer4->GetStaticBox(), wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_buttonSave, 0, wxALL, 5 );

	m_staticline22 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline22, 0, wxEXPAND | wxALL, 5 );

	m_staticline23 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline23, 0, wxEXPAND | wxALL, 5 );

	m_staticline19 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline19, 0, wxEXPAND | wxALL, 5 );

	m_staticline24 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline24, 0, wxALL|wxEXPAND, 5 );

	m_bButtonBearing1 = new wxButton( sbSizer4->GetStaticBox(), wxID_ANY, _("EBL"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_bButtonBearing1, 0, wxALL, 5 );

	m_staticline25 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline25, 0, wxEXPAND | wxALL, 5 );

	m_Lat1 = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_Lat1, 0, wxALL, 5 );

	m_button8 = new wxButton( sbSizer4->GetStaticBox(), wxID_ANY, _("EBL Off"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_button8, 0, wxALL, 5 );

	m_staticline26 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline26, 0, wxEXPAND | wxALL, 5 );

	m_Lon1 = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_Lon1, 0, wxALL, 5 );

	m_staticline27 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline27, 0, wxEXPAND | wxALL, 5 );

	m_staticline28 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline28, 0, wxEXPAND | wxALL, 5 );

	m_staticline29 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline29, 0, wxEXPAND | wxALL, 5 );

	m_staticline30 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline30, 0, wxEXPAND | wxALL, 5 );

	m_staticline31 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline31, 0, wxEXPAND | wxALL, 5 );

	m_staticline32 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer2->Add( m_staticline32, 0, wxEXPAND | wxALL, 5 );


	bSizer1->Add( fgSizer2, 1, wxEXPAND, 5 );


	sbSizer4->Add( bSizer1, 1, wxEXPAND, 5 );


	m_panelObjects->SetSizer( sbSizer4 );
	m_panelObjects->Layout();
	sbSizer4->Fit( m_panelObjects );
	m_notebook1->AddPage( m_panelObjects, _("     Object Editor          "), true );

	bSizer3->Add( m_notebook1, 0, wxEXPAND | wxALL, 5 );


	fgSizer1->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer1 );
	this->Layout();
	fgSizer1->Fit( this );
	m_timer1.SetOwner( this, m_timer1.GetId() );
	m_menubar3 = new wxMenuBar( 0 );
	m_mHelp = new wxMenu();
	wxMenuItem* m_mInformation;
	m_mInformation = new wxMenuItem( m_mHelp, wxID_ANY, wxString( _("Guide") ) , wxEmptyString, wxITEM_NORMAL );
	m_mHelp->Append( m_mInformation );

	wxMenuItem* m_mAbout;
	m_mAbout = new wxMenuItem( m_mHelp, wxID_ANY, wxString( _("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_mHelp->Append( m_mAbout );

	m_menubar3->Append( m_mHelp, _("Help") );

	this->SetMenuBar( m_menubar3 );


	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( SARrouteUIDialogBase::OnClose ) );
	this->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( SARrouteUIDialogBase::key_shortcut ) );
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( SARrouteUIDialogBase::OnSize ) );
	m_treeCtrlRoutes->Connect( wxEVT_COMMAND_TREE_BEGIN_DRAG, wxTreeEventHandler( SARrouteUIDialogBase::OnBeginDrag ), NULL, this );
	m_treeCtrlRoutes->Connect( wxEVT_COMMAND_TREE_END_DRAG, wxTreeEventHandler( SARrouteUIDialogBase::OnEndDrag ), NULL, this );
	m_panelObjects->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( SARrouteUIDialogBase::key_shortcut ), NULL, this );
	m_buttonAddTestItems->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::AddTestItems ), NULL, this );
	m_bLoadRTZ->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::OnLoadRTZ ), NULL, this );
	m_buttonAttach->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::OnIndex ), NULL, this );
	m_buttonAttach1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::OnRange ), NULL, this );
	m_buttonAttach2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::OnDirection ), NULL, this );
	m_buttonSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::OnSaveObjects ), NULL, this );
	m_bButtonBearing1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::OnButtonEBL ), NULL, this );
	m_Lat1->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( SARrouteUIDialogBase::key_shortcut ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::OnButtonEBL_off ), NULL, this );
	m_Lon1->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( SARrouteUIDialogBase::key_shortcut ), NULL, this );
	this->Connect( m_timer1.GetId(), wxEVT_TIMER, wxTimerEventHandler( SARrouteUIDialogBase::OnTimer ) );
	m_mHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SARrouteUIDialogBase::OnInformation ), this, m_mInformation->GetId());
	m_mHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SARrouteUIDialogBase::OnAbout ), this, m_mAbout->GetId());
}

SARrouteUIDialogBase::~SARrouteUIDialogBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( SARrouteUIDialogBase::OnClose ) );
	this->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( SARrouteUIDialogBase::key_shortcut ) );
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( SARrouteUIDialogBase::OnSize ) );
	m_treeCtrlRoutes->Disconnect( wxEVT_COMMAND_TREE_BEGIN_DRAG, wxTreeEventHandler( SARrouteUIDialogBase::OnBeginDrag ), NULL, this );
	m_treeCtrlRoutes->Disconnect( wxEVT_COMMAND_TREE_END_DRAG, wxTreeEventHandler( SARrouteUIDialogBase::OnEndDrag ), NULL, this );
	m_panelObjects->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( SARrouteUIDialogBase::key_shortcut ), NULL, this );
	m_buttonAddTestItems->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::AddTestItems ), NULL, this );
	m_bLoadRTZ->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::OnLoadRTZ ), NULL, this );
	m_buttonAttach->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::OnIndex ), NULL, this );
	m_buttonAttach1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::OnRange ), NULL, this );
	m_buttonAttach2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::OnDirection ), NULL, this );
	m_buttonSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::OnSaveObjects ), NULL, this );
	m_bButtonBearing1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::OnButtonEBL ), NULL, this );
	m_Lat1->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( SARrouteUIDialogBase::key_shortcut ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SARrouteUIDialogBase::OnButtonEBL_off ), NULL, this );
	m_Lon1->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( SARrouteUIDialogBase::key_shortcut ), NULL, this );
	this->Disconnect( m_timer1.GetId(), wxEVT_TIMER, wxTimerEventHandler( SARrouteUIDialogBase::OnTimer ) );

}
