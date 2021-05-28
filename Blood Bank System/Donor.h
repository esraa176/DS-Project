#include <string>
#include"User.h"
#include<vector>
using namespace std;


vector <Donor> donorsList;


struct Date
{
	int day, month, year;
};

class Donor:public User
{
public:

	string   Blood_type, Disease;

	int Donor_count = 0;
	Date Latest_Donation_Date;

public:
	Donor();
	Donor(string, int, char, string, string,string, string, Date);
	void Donation_Request(int);
	void Update_Data(int);
	void Donor_page(int);
};
