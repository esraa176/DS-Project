#pragma once
#include <string>
#include <vector>
#include<queue>
#include"Blood.h"
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
	void Recipient_page(int, vector <Recipient>&, queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&);
	void Update_Data(int, vector <Recipient>&);
	void Delete_Account(int, vector <Recipient>&);
	void Search_for_Blood(queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&);
	void display_all_blood_data();
	void Request_Blood();
	void Recipient_Registeration_Page(vector <Recipient>& recipientsList, queue<Blood>& dataA, queue<Blood>& dataB, queue<Blood>& dataO, queue<Blood>& dataAB);
};
