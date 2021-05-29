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
void Donor::Donor_page(int userIndex, vector <Donor>& donorsList)
{


}
void Donor::Donation_Request(int indx, vector <Donor>& donorsList)
{
	queue<int> q;
	//q.enqueue(v[indx].Donor_ID);

}
void Donor::Update_Data(int New_Age, vector <Donor>& donorsList)
{

}
void Donor::Donor_Registeration(vector <Donor>& donorsList)
{
	string name, email, password, blood_type;
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
	//ms2ltosh 3la last donation date wala 3mltolo initialize????
	Date latest_donation_date;
	Donor reg(name, age, gender, email, password, blood_type, disease, latest_donation_date);
	donorsList.push_back(reg);

	cout << "\t\t\t\t REGISTERATION SUCCESSFUL! \n\t\t Welcome to Our Blood Bank Management System!\n";
	Donor_page(donorsList.size() - 1, donorsList);
}
