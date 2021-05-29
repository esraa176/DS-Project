#pragma once
#include "Donor.h"
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
	void Admin_page(int, vector <Admin>&);
	void validateRequests();
	void addDonors();
	void Admin_Register(vector <Admin>&);

	//display & validate donor's requests
	//Insert/Update/Delete the quantity of blood, and its received and expiry dates 
	//Insert/Update/Delete/Display data of donors 
	//Insert/Update/Delete/Display data of recipients
};
