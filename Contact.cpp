#include "Contact.h"
#include "IDGenerator.h"

Contact::Contact(wxString name) : name(name)  {
	id = IDGenerator::GetId();
	status = offline; // query client
}

Contact::Contact(long id) : id(id)  {
	name = _("blankity"); // read from persistant storage
	status = offline; // query client
}

void Contact::OpenChat(long id)  {

}
