#pragma once
#include <string>
using namespace std;
vector <Donor> donorsList;
struct Date
{
	int day, month, year;
};

class Donor
{
public:
	string Name, Email, Password, Blood_type;
	bool Disease = false;
	int ID, Age;
	int Donor_count = 0;
	char Gender;
	Date Latest_Donation_Date;

public:
	Donor();
	Donor(string, int, char, string, string, string,bool, Date);
	void Donation_Request(int);
	void Update_Data(int);
	void Delete_Account();
	void Donor_page(int);
	void Donor_Registeration();
};
