#pragma once
#include "Donor.h"
#include "Recipient.h"
#include <vector>
#include <string>
#include "User.h"
#include "Blood.h"

using namespace std;

class Admin : public User
{
public:
	string code = "Blood Bank";

public:
	Admin(string, int, char, string, string, int&);
	Admin();
	void Admin_page(int, vector <Admin>&, vector <Donor>&, vector <Recipient>&, queue<int>&, queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&, int&, int&, int&);
	void validateRequests(vector <Donor>&, queue <int>&, int&, queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&);
	void Display_requests(vector <Donor>&, queue <int>&, int&, queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&);
	void Admin_Register(vector <Admin>&, vector <Donor>&, vector <Recipient>&, queue<int>&, queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&, int&);
	void insertUser(vector <Admin>&, vector <Donor>&, vector <Recipient>&, queue<int>&, queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&, int&, int&, int&);
	void deleteUser(vector <Admin>&, vector <Donor>&, vector <Recipient>&);
	void updateUser(vector <Admin>&, vector <Donor>&, vector <Recipient>&);
	void insertBlood(queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&);
	void deleteBlood(queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&);
	void displayData(int, vector <Admin>&, vector <Donor>&, vector <Recipient>&, char);
	void Current_Date();
	void Set_DonationDate(vector <Donor>&, int);
	void Set_Nxt_DonationDate(vector <Donor>&, int);
	bool comparingDates(vector <Donor>&, int);
	int searchForUser(int, vector <Admin>&, vector <Donor>&, vector <Recipient>&, char);  //Takes id and user type('r'/'o'/'d'), returns user index in the vector.
	void displayBloodData(queue<Blood>&, queue<Blood>&, queue<Blood>&, queue<Blood>&);
};
