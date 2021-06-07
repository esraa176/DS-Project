#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include "Admin.h"
#include "Donor.h"
#include "Recipient.h"
#include "Blood.h"
#include "Files.h"

using namespace std;

Files file;
vector <Admin> adminsList;
vector <Recipient> recipientsList;
vector <Donor> donorsList;
queue <Blood> dataA, dataB, dataO, dataAB;
queue <int> Donor_Requests;

Date cdate;
int quantityA = 0, quantityB = 0, quantityC = 0, aID = -1, rID = -1, dID = -1;

void welcome_page();
void Login_Page();
void Registeration_Page();
void expiredBlood();

int main()
{
	//First thing in the program is to read all previous data from the files into Array Lists.
	file.Intialize_Vectors_Queues(adminsList, recipientsList, donorsList, dataA, dataB, dataO, dataAB, Donor_Requests, aID, rID, dID);

	//removing the expired blood from the queue
	expiredBlood();

	welcome_page();

	//Last thing in the program is to update all the files with the new data from the Array Lists.
	file.Update_Files(adminsList, recipientsList, donorsList, dataA, dataB, dataO, dataAB, Donor_Requests);

	return 0;
}

void welcome_page()
{
	while (true)
	{
		//cout << donorsList.size() << endl;
		cout << "\t\t\t\tWelcome to Blood Bank Management System\t\t\t\t\n";
		cout << "Please Enter the number of the option you want: \n";
		cout << "\t\t 1. If you want to sign in." << endl;
		cout << "\t\t 2. If you're new and want to sign up." << endl;
		cout << "\t\t 3. If you want to exit system." << endl;
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
				adminsList[i].Admin_page(i, adminsList, donorsList, recipientsList, Donor_Requests, dataA, dataB, dataO, dataAB, aID, rID, dID);
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
				recipientsList[i].Recipient_page(i, recipientsList, dataA, dataB, dataO, dataAB, rID);
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
				donorsList[i].Donor_page(i, donorsList, Donor_Requests, dID);
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
			reg.Donor_Registeration(donorsList, Donor_Requests, dID);
			cout << "\t\t\t\t REGISTERATION SUCCESSFUL! \n\t\t Welcome to Our Blood Bank Management System!\n";
			reg.Donor_page(donorsList.size() - 1, donorsList, Donor_Requests, dID);
			break;
		}
		else if (User_choice == 2)
		{
			//recipient account creation
			Recipient reg;
			reg.Recipient_Registeration_Page(recipientsList, dataA, dataB, dataO, dataAB, rID);
			cout << "\t\t\t\t REGISTERATION SUCCESSFUL! \n\t\t Welcome to Our Blood Bank Management System!\n";
			char recp_2nd_choice;
			cout << "Do you want to make any progress? ";
			cin >> recp_2nd_choice;
			if (recp_2nd_choice == 'Y' || recp_2nd_choice == 'y')
			{
				reg.Recipient_page(recipientsList.size() - 1, recipientsList, dataA, dataB, dataO, dataAB, rID);
			}
			else 
			{
				cout << "Thank you for choosing our system!";
			}
			break;
		}
		else if (User_choice == 3)
		{
			Admin reg;
			reg.Admin_Register(adminsList, donorsList, recipientsList, Donor_Requests, dataA, dataB, dataO, dataAB, aID);
			cout << "\t\t\t\t REGISTERATION SUCCESSFUL! \n\t\t Welcome to Our Blood Bank Management System!\n";
			reg.Admin_page(adminsList.size() - 1, adminsList, donorsList, recipientsList, Donor_Requests, dataA, dataB, dataO, dataAB, aID, rID, dID);
			break;
		}
		else
		{
			cout << "Invalid Choice, Please Enter a number(1, 2 or 3)\n";
			cin >> User_choice;
		}
	}
}


void expiredBlood()
{
	tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	cdate.day = newtime.tm_mday;

	cdate.month = 1 + newtime.tm_mon;

	cdate.year = 1900 + newtime.tm_year;

	int sizeA = dataA.size();
	for (int i = 0; i < sizeA; i++)
	{
		Blood a = dataA.front();
		bool expired = true;
		int dateNow = cdate.day + (cdate.month * 30) + (cdate.year * 30 * 12);
		int ExpiredDate = a.expiry.tm_mday + (a.expiry.tm_mon * 30) + (a.expiry.tm_year * 30 * 12);
		if (ExpiredDate < dateNow)
		{
			dataA.pop();
			file.bloodUpdate(dataA, dataB, dataO, dataAB);
		}
		else
		{
			break;
		}
	}
	int sizeB = dataB.size();
	for (int i = 0; i < sizeB; i++)
	{
		Blood b = dataB.front();
		bool expired = true;
		int dateNow = cdate.day + (cdate.month * 30) + (cdate.year * 30 * 12);
		int ExpiredDate = b.expiry.tm_mday + (b.expiry.tm_mon * 30) + (b.expiry.tm_year * 30 * 12);
		if (ExpiredDate < dateNow)
		{
			dataB.pop();
			file.bloodUpdate(dataA, dataB, dataO, dataAB);
		}
		else
		{
			break;
		}
	}
	int sizeO = dataO.size();
	for (int i = 0; i < sizeO; i++)
	{
		Blood o = dataO.front();
		bool expired = true;
		int dateNow = cdate.day + (cdate.month * 30) + (cdate.year * 30 * 12);
		int ExpiredDate = o.expiry.tm_mday + (o.expiry.tm_mon * 30) + (o.expiry.tm_year * 30 * 12);
		if (ExpiredDate < dateNow) {
			dataO.pop();
			file.bloodUpdate(dataA, dataB, dataO, dataAB);
		}
		else
		{
			break;
		}
	}
	int sizeAB = dataAB.size();
	for (int i = 0; i < sizeAB; i++)
	{
		Blood ab = dataAB.front();
		bool expired = true;
		int dateNow = cdate.day + (cdate.month * 30) + (cdate.year * 30 * 12);
		int ExpiredDate = ab.expiry.tm_mday + (ab.expiry.tm_mon * 30) + (ab.expiry.tm_year * 30 * 12);
		if (ExpiredDate < dateNow)
		{
			dataAB.pop();
			file.bloodUpdate(dataA, dataB, dataO, dataAB);
		}
		else
		{
			break;
		}
	}
}
