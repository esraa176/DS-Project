#pragma once
#include <string>
#include <vector>
#include<queue>
#include <ctime>
#include"User.h"
using namespace std;
struct Date
{
	int day = 0, month = 0, year = 0;
};
class Donor:public User
{
	//public:
	//	struct Date
	//	{
	//		int day = 0, month = 0, year = 0;
	//	}c_date;

public:

	string Name, Email, Password, Blood_type;
	bool isDisease, Other_Disease, Validated_Donor = false;
	int ID, Age;
	int Donor_count = 0;
	char Gender;
	Date Latest_Donation_Date;
	Date Nxt_Donation_Date;

public:
	Donor();
	Donor(string, int, char, string, string, string, bool, bool, Date, int&);
	void Donation_Request(int, vector<Donor>&, queue<int>&);
	void Update_Data(int, vector<Donor>&);
	void Delete_Account(int, vector<Donor>&);
	void Donor_page(int, vector<Donor>&, queue<int>&);
	void Donor_Registeration(vector<Donor>&, queue<int>&, int&);

};
