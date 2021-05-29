#pragma once
#include <string>
#include <vector>
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
	void Recipient_page(int, vector <Recipient>&);
	void Update_Data(int, vector <Recipient>&);
	void Delete_Account(int, vector <Recipient>&);
	void Search_for_Blood();
	void display_all_blood_data();
	void Request_Blood();
	void Recipient_Registeration_Page(vector <Recipient>&);
};
