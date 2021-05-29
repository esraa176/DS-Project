#pragma once
#include <string>
#include <vector>
using namespace std;

struct Date
{
	int day = 0, month = 0, year = 0;
};

class Donor
{
public:
	string Name, Email, Password, Blood_type;
	bool Disease; //leh bool????
	int ID, Age;
	int Donor_count = 0;
	char Gender;
	Date Latest_Donation_Date;

public:
	Donor();
	Donor(string, int, char, string, string, string, bool, Date);
	void Donation_Request(int, vector<Donor>&);
	void Update_Data(int, vector<Donor>&);
	void Delete_Account(int, vector<Donor>&);
	void Donor_page(int, vector<Donor>&);
	void Donor_Registeration(vector<Donor>&);
};
