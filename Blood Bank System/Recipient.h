
#include <string>
#include<vector>
#include"User.h"
using namespace std;

vector <Recipient> recipientsList;

class Recipient : public  User
{
public:
	
	string Hospital, DoctorofTheCase;
	
	string Blood_type;  //A, B, O, AB
	int Reciepient_count = 0;

public:
	Recipient(string, int, char, string, string, string, string, string);
	Recipient();
	void Recipient_page(int);
	void Update_Data(int);
	void Delete_Account();
	void Search_for_Blood();
	void Request_Blood();
};
