#pragma once
#include <string>
#include <vector>
#include<queue>
#include"Blood.h"
#include"User.h"
using namespace std;

class Recipient : public User
{
public:
	string  Hospital, DoctorofTheCase;
	string Blood_type;  //A, B, O, AB

public:
	Recipient(string, int, char, string, string, string, string, string, int&);
	Recipient();
	void Recipient_page(int, vector <Recipient>&, queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&);
	void Update_Data(int, vector <Recipient>&);
	void Delete_Account(int, vector <Recipient>&);
	void Search_for_Blood(vector <Recipient>&, int, queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&);
	void display_all_blood_data(queue<Blood>& dataA, queue<Blood>& dataB, queue<Blood>& dataO, queue<Blood>& dataAB);
	void Request_Blood(string, queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&);
	void Recipient_Registeration_Page(vector <Recipient>& recipientsList, queue<Blood>& dataA, queue<Blood>& dataB, queue<Blood>& dataO, queue<Blood>& dataAB, int&);
};
