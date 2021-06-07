#include "Donor.h"
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include "Files.h"
using namespace std;
Files fileD;

Donor::Donor()
{

}
Donor::Donor(string name, int age, char gender, string mail, string password, string blood_type, bool isdisease, bool other_disease, Date latest_donation_date, int& dID)
	:User(name, age, gender, mail, password)
{
	ID = dID;
	dID++;
	Blood_type = blood_type;
	isDisease = isdisease;
	Other_Disease = other_disease;
	Latest_Donation_Date = latest_donation_date;
}

void Donor::Donor_page(int userIndex, vector <Donor>& donorsList, queue <int>& Donor_Requests, int dID)
{
	char ch;
	do
	{
		int choice;

		cout << "Press 1 if you want to make a Donation Request\n";
		cout << "Press 2 if you want to Update your Data\n";
		cout << "Press 3 if you want to Delete your Account\n";
		cout << "Press 4 if you want to exit this menu\n";
		cin >> choice;
		switch (choice) {
		case 1:
			Donation_Request(userIndex, donorsList, Donor_Requests);
			//call donation req
			break;
		case 2:
			Update_Data(userIndex, donorsList,dID);
			//call up data
			break;
		case 3:
			Delete_Account(userIndex, donorsList,dID);
			cout << "You have successfully Deleted your Account!\n";
			//call deleteacc
			break;
		case 4:
			return;
			break;
		default:
			cout << "Invalid Choice\n";

		}

		cout << "Do you want to continue? (y/n)" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}
void Donor::Donation_Request(int userIndex, vector <Donor>& donorsList, queue<int>& Donor_Requests)
{
	Donor_Requests.push(donorsList[userIndex].ID);
	cout << "You Successfully Made a Donation Request!\n";
	fileD.requestsUpdate(Donor_Requests);
}
void Donor::Update_Data(int userIndex, vector <Donor>& donorsList,int dID)
{
	int choice, New_age;
	string pass;
	char ch;
	cout << "Press 1 to update your Age\n";
	cout << "Press 2 to change your health status\n";
	cout << "Press 3 to change your password\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Please enter your new age\n";
		cin >> New_age;
		donorsList[userIndex].Age = New_age;
		break;
	case 2:
		cout << "Do you suffer from any of these diseases : blood pressure disorders, thyroid disease, diabetes, cancer, heart disorders, hepatitis(y / n) ? " << endl;
		cin >> ch;
		if (ch == 'y' || ch == 'Y') {
			donorsList[userIndex].isDisease = true;
		}
		else
		{
			donorsList[userIndex].isDisease = false;
		}

		cout << "Do you suffer from any other dieases? (y/n)" << endl;
		cin >> ch;
		if (ch == 'y' || ch == 'Y') {
			donorsList[userIndex].Other_Disease = true;
		}
		else {
			donorsList[userIndex].Other_Disease = false;
		}
		break;
	case 3:
		cout << "Please enter your new Password\n";
		cin >> pass;
		donorsList[userIndex].Password = pass;
		break;
	default:
		cout << "Invalid Choice\n";
		break;
	}
	fileD.donorUpdate(donorsList, dID);
}
void Donor::Donor_Registeration(vector <Donor>& donorsList, queue<int>& Donor_Requests, int& dID)
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
	Date latest_donation_date;
	Donor reg(Name, Age, Gender, Email, Password, Blood_type, isDisease, Other_Disease, latest_donation_date, dID);
	donorsList.push_back(reg);
	fileD.donorUpdate(donorsList, dID);
	cout << "\t\t\t\t REGISTERATION SUCCESSFUL! \n\t\t Welcome to Our Blood Bank Management System!\n";
	Donor_page(donorsList.size() - 1, donorsList, Donor_Requests,dID);
}

void Donor::Delete_Account(int userIndex, vector<Donor>& donorsList, int dID) {
	donorsList.erase(next(donorsList.begin(), userIndex));
	fileD.donorUpdate(donorsList, dID);
}
