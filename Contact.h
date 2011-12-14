#include <string>

typedef enum {
	online,
	offline,
	away
} activeStatus;

class Contact { 
public:
	Contact(std::string name);
	Contact(int id);
	void OpenChat(int id);
	
private: 
	int id;
	std::string name;
	activeStatus status;	
};