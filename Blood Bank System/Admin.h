#pragma once
#include "Donor.h"
#include"Recipient.h"
#include <vector>
#include <string>
using namespace std;

class Admin
{
public:
	int ID, Age;
	string Name, Email, Password, code = "Blood Bank";
	char Gender;
	int Admin_count = 0;

public:
	Admin(string, int, char, string, string);
	Admin();
	void Admin_page(int, vector <Admin>&, vector <Donor>&, vector <Recipient>&, queue<int>&);
	void validateRequests();
	void Admin_Register(vector <Admin>&, vector <Donor>&, vector <Recipient>&, queue<int>&);
	void insertUser(vector <Admin>&, vector <Donor>&, vector <Recipient>&, queue<int>&);
	void deleteUser(vector <Admin>&, vector <Donor>&, vector <Recipient>&);
	void updateUser(vector <Admin>&, vector <Donor>&, vector <Recipient>&);
	void insertBlood();
	void deleteBlood();
	void updateBlood();
	void displayData(int, vector <Admin>&, vector <Donor>&, vector <Recipient>&, char);
};
