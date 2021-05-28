#pragma once
#include <string>
using namespace std;

class Recipient
{
public:
	int ID, Age;
	string Name, Email, Password, Hospital, DoctorofTheCase;
	char Gender;
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
