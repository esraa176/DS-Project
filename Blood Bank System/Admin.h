#pragma once
#include "Donor.h"
#include"Recipient.h"
#include <vector>
#include <string>
//#include"User.h"
#include"Blood.h"
using namespace std;

class Admin //: public User
{
public:
	int ID, Age;
	string Name, Email, Password, code = "Blood Bank";
	char Gender;
	int Admin_count = 0;

public:
	Admin(string, int, char, string, string, int&);
	Admin();
	void Admin_page(int, vector <Admin>&, vector <Donor>&, vector <Recipient>&, queue<int>&, queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&, int&, int&, int&);
	void validateRequests(vector <Donor>&, queue <int>&);
	void Display_requests(vector <Donor>&, queue <int>&);
	void Admin_Register(vector <Admin>&, vector <Donor>&, vector <Recipient>&, queue<int>&, queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&, int&, int&, int&);
	void insertUser(vector <Admin>&, vector <Donor>&, vector <Recipient>&, queue<int>&, queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&, int&, int&, int&);
	void deleteUser(vector <Admin>&, vector <Donor>&, vector <Recipient>&);
	void updateUser(vector <Admin>&, vector <Donor>&, vector <Recipient>&);
	void insertBlood();
	void deleteBlood();
	void updateBlood();
	void displayData(int, vector <Admin>&, vector <Donor>&, vector <Recipient>&, char);
	void bloodDate();
};
