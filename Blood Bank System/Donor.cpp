#include "Donor.h"
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


Donor::Donor()
{

}
Donor::Donor(string name, int age, char gender, string mail, string password, string blood_type, bool isdisease,bool other_disease, Date latest_donation_date)
{
	ID = Donor_count;
	Donor_count++;
	Name = name;
	Age = age;
	Gender = gender;
	Email = mail;
	Password = password;
	Blood_type = blood_type;
	isDisease = isdisease;
	Other_Disease = other_disease;
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
	char is_Disease, other_disease;
	cout << "Please enter your Name:" << endl;
	cin >> Name;
	cout << "Please enter your email:" << endl;
	cin >> Email;
	cout << "Please enter your password:" << endl;
	cin >> Password;
	cout << "Please enter your Blood Type:" << endl;
	cin >> Blood_type;
	cout << "Please enter your Age:" << endl;
	cin >> Age;
	cout << "Please enter your Gender:" << endl;
	cin >> Gender;
	cout << "Do you suffer from any of these diseases :blood pressure disorders, thyroid disease, diabetes, cancer, heart disorders, hepatitis (y/n)?" << endl;
	cin >> is_Disease;
	if (is_Disease == 'y' || is_Disease == 'Y') {
		isDisease = true;
	}
	else
	{
		isDisease = false;
	}

	cout << "Do you suffer from any other dieases? (y/n)" << endl;
	cin >> other_disease;
	if (other_disease == 'y' || other_disease == 'Y') {
		Other_Disease = true;
	}
	else {
		Other_Disease = false;
	}
	//ms2ltosh 3la last donation date wala 3mltolo initialize????
	Date latest_donation_date;
	Donor reg(Name, Age, Gender, Email, Password, Blood_type, isDisease,Other_Disease, latest_donation_date);
	donorsList.push_back(reg);

	cout << "\t\t\t\t REGISTERATION SUCCESSFUL! \n\t\t Welcome to Our Blood Bank Management System!\n";
	Donor_page(donorsList.size() - 1, donorsList);
}
