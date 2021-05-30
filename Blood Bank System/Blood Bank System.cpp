#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<queue>
//#include "ArrList.cpp"
//#include "QueueArr.cpp"
#include "Admin.h"
#include "Donor.h"
#include "Recipient.h"

using namespace std;

fstream adminsFile("admins.txt", ios::in | ios::out | ios::app);
fstream recipientsFile("recipients.txt", ios::in | ios::out | ios::app);
fstream donorsFile("donors.txt", ios::in | ios::out | ios::app);

vector <Admin> adminsList;
vector <Recipient> recipientsList;
queue <int> Donor_Requests;
vector <Donor> donorsList;

struct Blood
{
	int quantity;
	Date received;
	Date expiry;
}A, B, AB, O;

void welcome_page();
void Login_Page();
void Registeration_Page();
void Intialize_Vectors();
void Update_Files();

int main()
{
	//First thing in the program is to read all previous data from the files into Array Lists.
	Intialize_Vectors();

	welcome_page();


	//Last thing in the program is to update all the files with the new data from the Array Lists.
	Update_Files();

	return 0;
}

void welcome_page() {
	while (true)
	{
		cout << "\t\t\t\tWelcome to Blood Bank Management System\t\t\t\t\n";
		cout << "Please Enter the number of the option you want: \n";
		cout << "\t\t 1. If you want to sign in." << endl;
		cout << "\t\t 2. If you're new and want to sign up." << endl;
		cout << "\t\t 3. If you want to exit." << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			Login_Page();
			break;
		}
		else if (choice == 2)
		{
			Registeration_Page();
			break;
		}
		else if (choice == 3)
		{
			break;
		}
		else
		{
			cout << "Invalid choice, Please try again." << endl;
		}
	}
}

void Intialize_Vectors()
{

	Admin admin;
	while (adminsFile >> admin.ID >> admin.Name >> admin.Age >> admin.Gender >> admin.Email >> admin.Password)
	{
		adminsList.push_back(admin);
	}
	adminsFile.close();


	Recipient r;
	while (recipientsFile >> r.ID >> r.Name >> r.Age >> r.Gender >> r.Email >> r.Password >> r.Blood_type >> r.Hospital >> r.DoctorofTheCase)
	{

		recipientsList.push_back(r);
	}
	recipientsFile.close();


	Donor d;
	while (donorsFile >> d.ID >> d.Name >> d.Age >> d.Gender >> d.Email >> d.Password >> d.Blood_type >> d.isDisease >> d.Other_Disease >> d.Latest_Donation_Date.day >> d.Latest_Donation_Date.month >> d.Latest_Donation_Date.year)
	{
		donorsList.push_back(d);
	}
	donorsFile.close();
}

void Login_Page()
{
	cout << "\t\t\t Login Page\n";
	bool isFound = false;
	int IndexofUser;
	char user_type; // A = Admin, R = Reciepient, D = Donor
	string mail, password;
	while (true)
	{
		isFound = false;
		cout << "Please Enter Your Email: ";
		cin >> mail;
		cout << "Please Enter Your Password: ";
		cin >> password;
		for (int i = 0; i < adminsList.size(); i++)
		{
			if (adminsList[i].Email == mail && adminsList[i].Password == password)
			{
				IndexofUser = i;
				user_type = 'A';
				adminsList[i].Admin_page(i, adminsList, donorsList, recipientsList);
				isFound = true;
				break;
			}
		}
		for (int i = 0; i < recipientsList.size() && !isFound; i++)
		{
			if (recipientsList[i].Email == mail && recipientsList[i].Password == password)
			{
				IndexofUser = i;
				user_type = 'R';
				recipientsList[i].Recipient_page(i, recipientsList);
				welcome_page();
				isFound = true;
				break;
			}
		}
		for (int i = 0; i < donorsList.size() && !isFound; i++)
		{
			if (donorsList[i].Email == mail && donorsList[i].Password == password)
			{
				IndexofUser = i;
				user_type = 'D';
				donorsList[i].Donor_page(i, donorsList, Donor_Requests);
				isFound = true;
				break;
			}
		}

		if (isFound)
		{
			break;
		}
		cout << "Wrong Email or Password. Please try again.\n";
	}
}

void Registeration_Page()
{
	cout << "\t\t\t Registration Page\n";
	cout << "Please specify what use type you will be: (Enter the number of your choice)\n";
	cout << "\t 1. Donor: Donates blood to those who need it.\n";
	cout << "\t 2. Recipient: Recieves blood donations from donors.\n";
	cout << "\t 3. Admin: Validates donors' blood donation requests and manage the system's data.\n";
	int User_choice;
	cin >> User_choice;
	while (true) {
		if (User_choice == 1)
		{
			Donor reg;
			reg.Donor_Registeration(donorsList, Donor_Requests);
			break;
		}
		else if (User_choice == 2)
		{
			//recipient account creation
			Recipient reg;
			reg.Recipient_Registeration_Page(recipientsList);
			welcome_page();

			break;
		}
		else if (User_choice == 3)
		{
			Admin reg;
			reg.Admin_Register(adminsList, donorsList, recipientsList);
			break;
		}
		else
		{
			cout << "Invalid Choice, Please Enter a number(1, 2 or 3)\n";
			cin >> User_choice;
		}
	}


}

void Update_Files()
{
	adminsFile.open("admins.txt", ofstream::out | ofstream::trunc);
	for (int i = 0; i < adminsList.size(); i++)
	{
		adminsFile << adminsList[i].ID << " " << adminsList[i].Name << " " << adminsList[i].Age << " ";
		adminsFile << adminsList[i].Gender << " " << adminsList[i].Email << " " << adminsList[i].Password << endl;
	}
	adminsFile.close();

	recipientsFile.open("recipients.txt", ofstream::out | ofstream::trunc);
	for (int i = 0; i < recipientsList.size(); i++)
	{
		recipientsFile << recipientsList[i].ID << " " << recipientsList[i].Name << " " << recipientsList[i].Age << " ";
		recipientsFile << recipientsList[i].Gender << " " << recipientsList[i].Email << " " << recipientsList[i].Password << " ";
		recipientsFile << recipientsList[i].Blood_type << " " << recipientsList[i].Hospital << " " << recipientsList[i].DoctorofTheCase << endl;
	}
	recipientsFile.close();

	donorsFile.open("donors.txt", ofstream::out | ofstream::trunc);
	for (int i = 0; i < donorsList.size(); i++)
	{
		donorsFile << donorsList[i].ID << " " << donorsList[i].Name << " " << donorsList[i].Age << " " << donorsList[i].Gender << " ";
		donorsFile << donorsList[i].Email << " " << donorsList[i].Password << " " << donorsList[i].Blood_type << " " << donorsList[i].isDisease << " " << donorsList[i].Other_Disease << " ";
		donorsFile << donorsList[i].Latest_Donation_Date.day << " " << donorsList[i].Latest_Donation_Date.month << " " << donorsList[i].Latest_Donation_Date.year << endl;
	}
	donorsFile.close();
}
