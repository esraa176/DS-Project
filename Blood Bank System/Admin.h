#pragma once
#include "Donor.h"
#include <string>
using namespace std;

class Admin
{
public:
	int ID, Age;
	string Name, Email, Password;
	char Gender;
	int Admin_count = 0;

public:
	Admin(string, int, char, string, string);
	Admin();
	void Admin_page(int);
	void validateRequests();
	void addDonors();


	//display & validate donor's requests
	//Insert/Update/Delete the quantity of blood, and its received and expiry dates 
	//Insert/Update/Delete/Display data of donors 
	//Insert/Update/Delete/Display data of recipients
};
