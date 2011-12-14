#include "ClientFrame.h"  
#include <vector>
#include "AddContactFrame.h"

BEGIN_EVENT_TABLE(ClientFrame, wxFrame)
    EVT_MENU(ID_Quit,  ClientFrame::OnQuit)
    EVT_MENU(ID_About, ClientFrame::OnAbout)
    EVT_MENU(ID_Add_Contact, ClientFrame::OnAddContact)
END_EVENT_TABLE()
 

ClientFrame::ClientFrame(std::vector<Contact>& contacts,  const wxString& title, const wxPoint& pos, const wxSize& size) 
       : wxFrame(NULL, -1, title, pos, size), contacts(contacts) {
	 
    wxMenu *menuFile = new wxMenu;
    wxBoxSizer * box = new wxBoxSizer(wxVERTICAL);
    
    ContactList * contactList = new ContactList(contacts, this, wxNewId());
    
    menuFile->Append( ID_Add_Contact, _("&Add Contact") );
    menuFile->Append( ID_About, _("&About...") );
    menuFile->AppendSeparator();
    menuFile->Append( ID_Quit, _("E&xit") );
    
    box->Add(contactList, 1, wxEXPAND, 0);
    SetSizer(box);
    
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, _("&Main") ); 
    SetMenuBar( menuBar );

    CreateStatusBar();
    SetStatusText( _("Ⓐ") );
} 

void ClientFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
    Close(true);
}
 
void ClientFrame::OnAddContact(wxCommandEvent& WXUNUSED(event)) {
      AddContactFrame *frame = new AddContactFrame( _("Add Contact"), wxPoint(50, 50), wxSize(275, 50) );
      frame->Show(true);
      
}

void ClientFrame::OnAbout(wxCommandEvent& WXUNUSED(event)) {
    wxMessageBox( _("This is an encrypted chat client,\n keep the sniffers off your convo!"), 
			    _("About HushChat"),
			    wxOK | wxICON_INFORMATION,
			    this );
}

