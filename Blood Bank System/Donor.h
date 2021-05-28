#pragma once
#include <string>
using namespace std;

struct Date
{
	int day, month, year;
};

class Donor
{
public:
	string Name, Email, Password, Blood_type, Disease;
	int ID, Age;
	int Donor_count = 0;
	char Gender;
	Date Latest_Donation_Date;

public:
	Donor();
	Donor(string, int, char, string, string, string, string, Date);
	void Donation_Request(int);
	void Update_Data(int);
	void Delete_Account();
	void Donor_page(int);
};
