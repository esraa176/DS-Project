#include "Donor.h"
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


Donor::Donor()
{

}
Donor::Donor(string name, int age, char gender, string mail, string password, string blood_type, string disease, Date latest_donation_date)
{
	ID = Donor_count;
	Donor_count++;
	Name = name;
	Age = age;
	Gender = gender;
	Email = mail;
	Password = password;
	Blood_type = blood_type;
	Disease = disease;
	Latest_Donation_Date = latest_donation_date;
}
void Donor::Donor_page(int userIndex)
{
	
	
}
void Donor::Donation_Request(int indx)
{
	queue<int> q;
	//q.enqueue(v[indx].Donor_ID);

}
void Donor::Update_Data(int New_Age)
{

}
