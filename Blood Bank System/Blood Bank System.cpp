#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include "ArrList.cpp"
//#include "QueueArr.cpp"
#include "Admin.h"
#include "Donor.h"
#include "Recipient.h"

using namespace std;

vector <Admin> adminsList;
vector <Recipient> recipientsList;
vector <Donor> donorsList;

struct Blood
{
	int quantity;
	Date received;
	Date expiry;
};

void Login_Page();
void Registeration_Page();
void Intialize_Vectors();
void Update_Files();

int main()
{
	//First thing in the program is to read all previous data from the files into Array Lists.
	Intialize_Vectors();

	while (true)
	{
		cout << "\t\t\t\tWelcome to Blood Bank Management System\t\t\t\t\n";
		cout << "Please Enter the number of the option you want: \n";
		cout << "\t\t 1. If you already have an account." << endl;
		cout << "\t\t 2. If you're new to sign up." << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			Login_Page();
		}
		else if (choice == 2)
		{
			Registeration_Page();
		}
		else
		{
			cout << "Invalid choice, Please try again." << endl;
		}
	}

	//Last thing in the program is to update all the files with the new data from the Array Lists.
	Update_Files();


	return 0;
}

void Intialize_Vectors()
{
	fstream adminsFile("admins.txt", ios::in | ios::out | ios::app);
	Admin admin;
	while (adminsFile >> admin.ID >> admin.Name >> admin.Age >> admin.Gender >> admin.Email >> admin.Password)
	{
		adminsList.push_back(admin);
	}
	adminsFile.close();

	fstream recipientsFile("recipients.txt", ios::in | ios::out | ios::app);
	Recipient r;
	while (recipientsFile >> r.ID >> r.Name >> r.Age >> r.Gender >> r.Email >> r.Password>> r.Blood_type>> r.Hospital >> r.DoctorofTheCase)
	{

		recipientsList.push_back(r);
	}
	recipientsFile.close();

	fstream donorsFile("donors.txt", ios::in | ios::out | ios::app);
	Donor d;
	while (donorsFile >> d.ID >> d.Name >> d.Age >> d.Gender >> d.Email >> d.Password >> d.Blood_type >> d.Disease >> d.Latest_Donation_Date.day >> d.Latest_Donation_Date.month >> d.Latest_Donation_Date.year)
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
		cout << "\nPlease Enter Your Password: ";
		cin >> password;
		for (int i = 0; i < adminsList.size(); i++)
		{
			if (adminsList[i].Email == mail && adminsList[i].Password == password)
			{
				IndexofUser = i;
				user_type = 'A';
				adminsList[i].Admin_page(i);
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
				recipientsList[i].Recipient_page(i);
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
				donorsList[i].Donor_page(i);
				isFound = true;
				break;
			}
		}

		if (!isFound)
		{
			cout << "Wrong Email or Password. Please try again.\n";
		}
	}
}

void Registeration_Page()
{
	cout << "\t\t\t Registration Page\n";
	cout << "Please specify what use type you will be: (Enter the number of your choice)";
	cout << "\t 1. Donor: Donates blood to those who need it.\n";
	cout << "\t 2. Recipient: Recieves blood donations from donors.\n";
	cout << "\t 3. Admin: Validates donors' blood donation requests and manage the system's data.\n";
	int User_choice;
	cin >> User_choice;
	while (true) {
		if (User_choice == 1) {
			//donor account creation
			break;
		}
		else if (User_choice == 2) {
			//recipient account creation
			break;
		}
		else if (User_choice == 3) {
			//admin account creation
			break;
		}
		else
		{
			cout << "Invalid Choice, Please Enter a number(1, 2 or 3)\n";
			cin >> User_choice;
		}
	}



	cout << "\t\t REGISTERATION SUCCESSFUL!\n Welcome to our Blood Bank Management System!\n"; //display this in constructors not here!
}

void Update_Files()
{
	fstream adminsFile("admins.txt", ios::in | ios::out | ios::app | ios::trunc);
	for (int i = 0; i < adminsList.size(); i++)
	{
		adminsFile << adminsList[i].ID << " " << adminsList[i].Name << " " << adminsList[i].Age << " ";
		adminsFile << adminsList[i].Gender << " " << adminsList[i].Email << " " << adminsList[i].Password << endl;
	}
	adminsFile.close();

	fstream recipientsFile("recipients.txt", ios::in | ios::out | ios::app | ios::trunc);
	for (int i = 0; i < recipientsList.size(); i++)
	{
		recipientsFile << recipientsList[i].ID << " " << recipientsList[i].Name << " " << recipientsList[i].Age << " ";
		recipientsFile << recipientsList[i].Gender << " " << recipientsList[i].Email << " " << recipientsList[i].Password << " ";
		recipientsFile << recipientsList[i].Blood_type << " " << recipientsList[i].Hospital << " " << recipientsList[i].DoctorofTheCase << endl;
	}
	recipientsFile.close();

	fstream donorsFile("donors.txt", ios::in | ios::out | ios::app | ios::trunc);
	for (int i = 0; i < donorsList.size(); i++)
	{
		donorsFile << donorsList[i].ID << " " << donorsList[i].Name << " " << donorsList[i].Age << " " << donorsList[i].Gender << " ";
		donorsFile << donorsList[i].Email << " " << donorsList[i].Password << " " << donorsList[i].Blood_type << " " << donorsList[i].Disease << " ";
		donorsFile << donorsList[i].Latest_Donation_Date.day << " " << donorsList[i].Latest_Donation_Date.month << " " << donorsList[i].Latest_Donation_Date.year << endl;
	}
	donorsFile.close();
}