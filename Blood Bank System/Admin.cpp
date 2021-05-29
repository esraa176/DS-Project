#include"Admin.h"
#include<iostream>
#include<string>
#include <vector>
#include"Donor.h"
using namespace std;

Admin::Admin()
{

}
Admin::Admin(string name, int age, char gender, string email, string password)
{
	Name = name;
	Age = age;
	Gender = gender;
	Email = email;
	Password = password;
	ID = Admin_count;
	Admin_count++;
}

void Admin::Admin_page(int userIndex, vector <Admin>& adminsList)
{

}
void Admin::validateRequests()
{

}

void Admin::addDonors()
{

}

void Admin::Admin_Register(vector <Admin>& adminsList)
{
	cout << "Please enter Admin's code: ";
	string input_code;
	cin.ignore();
	getline(cin, input_code);
	if (input_code != code)
	{
		cout << "\nInvalid code. You can't be an admin.\n";
		return;
	}
	int age;
	string name, email, pass;
	char gender;
	cout << "Please enter your name, age and gender (M/F).\n";
	cin >> name >> age >> gender;
	cout << "Please enter your Email and Password.\n";
	cin >> email >> pass;
	Admin reg(name, age, gender, email, pass);
	adminsList.push_back(reg);
	cout << "\t\t\t\t REGISTERATION SUCCESSFUL! \n\t\t Welcome to Our Blood Bank Management System!\n";
	Admin_page(adminsList.size() - 1, adminsList);
}
