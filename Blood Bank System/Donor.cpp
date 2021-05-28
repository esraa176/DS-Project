#include "Donor.h"
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

Donor::Donor()
{

}
Donor::Donor(string name, int age, char gender, string mail, string password, string blood_type, bool disease, Date latest_donation_date)
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
	//queue<int> q;
	

}
void Donor::Update_Data(int New_Age)
{

}
void Donor_Registeration() {
	string name, email, password,blood_type;
	int age;
	bool isDisease = false, Other_Disease = false;
	char gender, disease;
	cout << "Please enter your Name:" << endl;
	cin >> name;
	cout << "Please enter your email:" << endl;
	cin >> email;
	cout << "Please enter your password:" << endl;
	cin >> password;
	cout << "Please enter your Blood Type:" << endl;
	cin >> blood_type;
	cout << "Please enter your Age:" << endl;
	cin >> age;
	cout << "Please enter your Gender:" << endl;
	cin >> gender;
	cout << "Do you suffer from any of these diseases? :blood pressure disorders, thyroid disease, diabetes, cancer, heart disorders, hepatitis (y/n)" << endl;
	cin >> disease;
	if (disease == 'y' || disease == 'Y') {
		isDisease = true;
		}
	else {
		cout << "Do you suffer from any other dieases? (y/n)" << endl;
		Other_Disease = true;
	}
	donorsList.push_back(Donor(name, age, gender, email, password, blood_type, disease, latest_donation_date));
}
