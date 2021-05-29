#include"Admin.h"
#include<iostream>
#include<string>
#include <vector>
#include"Donor.h"
#include"Recipient.h"
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

void Admin::Admin_page(int userIndex, vector <Admin>& adminsList, vector <Donor>& donorsList, vector <Recipient>& recipientsList)
{
	cout << "\t\t Enter 1 to display & validate donor's requests." << endl;
	cout << "\t\t Enter 2 to Insert/Update/Delete the quantity of blood." << endl;
	cout << "\t\t Enter 3 to Insert/Update/Delete data of users." << endl;
	int choice;
	cin >> choice;
	while (true)
	{
		if (choice == 1)
		{
			validateRequests();
			break;
		}
		else if (choice == 2)
		{
			while (true)
			{
				cout << "Enter the number of your choice:" << endl;
				cout << "1-Insert" << endl;
				cout << "2-Update" << endl;
				cout << "3-Delete" << endl;
				int choice2;
				cin >> choice2;
				if (choice2 == 1)
				{
					insertBlood();
					break;
				}
				else if (choice2 == 2)
				{
					updateBlood();
					break;
				}
				else if (choice2 == 3)
				{
					deleteBlood();
					break;
				}
				else
				{
					cout << "Invalid Choice, Please Enter a number(1, 2 or 3)\n";
					cin >> choice2;
				}
			}
			break;

		}

		else if (choice == 3)
		{
			while (true)
			{
				cout << "Enter the number of your choice:" << endl;
				cout << "1-Insert" << endl;
				cout << "2-Update" << endl;
				cout << "3-Delete" << endl;
				int choice2;
				cin >> choice2;
				if (choice2 == 1)
				{
					insertUser(adminsList, donorsList, recipientsList);
					break;
				}
				else if (choice2 == 2)
				{
					updateUser(adminsList);
					break;
				}
				else if (choice2 == 3)
				{
					deleteUser(adminsList,donorsList,recipientsList);
					break;
				}
				else
				{
					cout << "Invalid Choice, Please Enter a number(1, 2 or 3)\n";
					cin >> choice2;
				}
			}
			break;
		}
		
	}
}
void Admin::validateRequests()
{

}

void Admin::Admin_Register(vector <Admin>& adminsList, vector <Donor>& donorsList, vector <Recipient>& recipientsList)
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
	insertUser(adminsList, donorsList, recipientsList);
	cout << "\t\t\t\t REGISTERATION SUCCESSFUL! \n\t\t Welcome to Our Blood Bank Management System!\n";
	Admin_page(adminsList.size() - 1, adminsList, donorsList, recipientsList);
}
void Admin::insertUser(vector <Admin>& adminsList, vector <Donor>& donorsList, vector <Recipient>& recipientsList)
{
	int age;
	string name, email, pass,blood_type, hospital, doctor;
	char gender;
	bool isdisease, other_disease;
	Date latest_donation_date;
	cout << "Enter the number of your choice:" << endl;
	cout << "1-Insert admin." << endl;
	cout << "2-Insert donor." << endl;
	cout << "3-Insert recipient." << endl;
	int choice;
	cin >> choice;
	cout << "Please enter name, age and gender (M/F).\n";
	cin >> name >> age >> gender;
	cout << "Please enter Email and Password.\n";
	cin >> email >> pass;
	while (true)
	{
		if (choice == 1)
		{
			cout << "Please enter your data.\n";
			cout << "Name: "; cin >> name;
			cout << "Age: "; cin >> age;
			cout << "Gender (M\F): "; cin >> gender;
			cout << "Email: "; cin >> email;
			cout << "Password: "; cin >> pass;
			Admin reg(name, age, gender, email, pass);
			adminsList.push_back(reg);
			cout << "Insertion is successfully done." << endl;
			cout << "_________________________________" << endl;
			break;
		}
		else if (choice == 2)
		{
			cout << "Please enter your data.\n";
			cout << "Name: "; cin >> name;
			cout << "Age: "; cin >> age;
			cout << "Gender (M\F): "; cin >> gender;
			cout << "Email: "; cin >> email;
			cout << "Password: "; cin >> pass;
			cout << "Blood Type: "; cin >> blood_type;
			cout << "Do you have any disease?: "; cin >> isdisease;
			
			//??????????????????????????????????????
			cin >> other_disease;
			cout << "Your last donation date?\n";
			cout << "Day: "; cin >> latest_donation_date.day;
			cout << "Month: "; cin >> latest_donation_date.month;
			cout << "Year: "; cin >> latest_donation_date.year;
			Donor reg(name, age, gender, email, pass, blood_type, isdisease, other_disease, latest_donation_date);
			donorsList.push_back(reg);
			cout << "Insertion is successfully done." << endl;
			cout << "_________________________________" << endl;
			break;
		}
		else if (choice == 3)
		{
			cout << "Please enter your data.\n";
			cout << "Name: "; cin >> name;
			cout << "Age: "; cin >> age;
			cout << "Gender (M\F): "; cin >> gender;
			cout << "Email: "; cin >> email;
			cout << "Password: "; cin >> pass;
			cout << "Blood Type: "; cin >> blood_type;
			cout << "Hospital: "; cin >> hospital;
			cout << "Doctor: "; cin >> doctor;
			Recipient reg(name, age, gender, email, pass, blood_type, hospital, doctor);
			recipientsList.push_back(reg);
			cout << "Insertion is successfully done." << endl;
			cout << "_________________________________" << endl;
			break;
		}
		else
		{
			cout << "Invalid Choice, Please Enter a number(1, 2 or 3)\n";
			cin >> choice;
		}
	}
	
}
void Admin::deleteUser(vector <Admin>&adminsList, vector <Donor>&donorsList, vector <Recipient>&recipientsList)
{
	cout << "Enter the number of your choice:" << endl;
	cout << "1-Delete admin." << endl;
	cout << "2-Delete donor." << endl;
	cout << "3-Delete recipient." << endl;
	int choice;
	cin >> choice;
	cout << "Please enter user's ID.\n";
	int id;
	cin >> id;
	bool isFound = false;
	while (true)
	{
		if (choice == 1)
		{
			for (int i = 0; i < adminsList.size(); i++)
			{
				if (id == adminsList[i].ID)
				{
					adminsList.erase(next(adminsList.begin(), i));
					isFound = true;
					cout << "Deletion is successfully done." << endl;
					cout << "_________________________________" << endl;
					break;
				}
			}
			if (isFound)
			{
				break;
			}
		}
		else if (choice == 2)
		{
			for (int i = 0; i < donorsList.size(); i++)
			{
				if (id == donorsList[i].ID)
				{
					donorsList.erase(next(donorsList.begin(), i));
					isFound = true;
					cout << "Deletion is successfully done." << endl;
					cout << "_________________________________" << endl;
					break;
				}
			}
			if (isFound)
			{
				break;
			}
		}
		else if (choice == 3)
		{
			for (int i = 0; i < recipientsList.size(); i++)
			{
				if (id == recipientsList[i].ID)
				{
					recipientsList.erase(next(recipientsList.begin(), i));
					isFound = true;
					cout << "Deletion is successfully done." << endl;
					cout << "_________________________________" << endl;
					break;
				}
			}
			if (isFound)
			{
				break;
			}
		}
		else
		{
			cout << "Invalid Choice, Please Enter a number(1, 2 or 3)\n";
			cin >> choice;
			continue;
		}

		if (!isFound)
		{
			cout << "Incorrect ID, Please try again." << endl;
			cin >> id;
		}
	}
		
}
void Admin::updateUser(vector <Admin>& adminsList)
{

}
void Admin::insertBlood()
{

}
void Admin::deleteBlood()
{

}
void Admin::updateBlood()
{

}
