#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
//#include "ArrList.cpp"
//#include "QueueArr.cpp"
#include "Admin.h"
#include "Donor.h"
#include "Recipient.h"
#include "Blood.h"
#include "Files.h"

using namespace std;


Files file;
//vector<User> user;
vector <Admin> adminsList;
vector <Recipient> recipientsList;
vector <Donor> donorsList;
queue <Blood> dataA, dataB, dataO, dataAB;
queue <int> Donor_Requests;


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
	file.Update_Files(adminsList, recipientsList, donorsList, dataA, dataB, dataO, dataAB, Donor_Requests, aID, rID, dID);

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
				recipientsList[i].Recipient_page(i, recipientsList, dataA, dataB, dataO, dataAB);
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
			reg.Donor_Registeration(donorsList, Donor_Requests, dID);
			break;
		}
		else if (User_choice == 2)
		{
			//recipient account creation
			Recipient reg;
			reg.Recipient_Registeration_Page(recipientsList, dataA, dataB, dataO, dataAB, rID);
			welcome_page();
			break;
		}
		else if (User_choice == 3)
		{
			Admin reg;
			reg.Admin_Register(adminsList, donorsList, recipientsList, Donor_Requests, dataA, dataB, dataO, dataAB, aID, rID, dID);
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
	tm current_time;
	current_time.tm_mday = newtime.tm_mday;

	current_time.tm_mon = 1 + newtime.tm_mon;

	current_time.tm_year = 1900 + newtime.tm_year;

	 //pop type A expired blood
	for (int i = 0; i < dataA.size(); i++)
	{
		if (dataA._Get_container()[i].expiry.tm_mon == 12)
		{
			if (current_time.tm_mon == 1)
			{
				if (current_time.tm_mday > dataA._Get_container()[i].expiry.tm_mday)
				{
					dataA.pop();
				}
			}
			else if (current_time.tm_mon > 1 && current_time.tm_mon != 12)
			{
				dataA.pop();
			}
		}
		else if (current_time.tm_mon > dataA._Get_container()[i].expiry.tm_mon)
		{
			dataA.pop();
		}
		else if (current_time.tm_mon == dataA._Get_container()[i].expiry.tm_mon)
		{
			if (current_time.tm_mday >= dataA._Get_container()[i].expiry.tm_mday)
			{
				dataA.pop();
			}
		}
		else if (current_time.tm_year > dataA._Get_container()[i].expiry.tm_year)
		{
			dataA.pop();
		}
		else
		{
			break;
		}

	}

	 //pop type B expired blood
	for (int i = 0; i < dataB.size(); i++)
	{
		if (dataB._Get_container()[i].expiry.tm_mon == 12)
		{
			if (current_time.tm_mon == 1)
			{
				if (current_time.tm_mday > dataB._Get_container()[i].expiry.tm_mday)
				{
					dataB.pop();
				}
			}
			else if (current_time.tm_mon > 1 && current_time.tm_mon != 12)
			{
				dataB.pop();
			}
		}
		else if (current_time.tm_mon > dataB._Get_container()[i].expiry.tm_mon)
		{
			dataB.pop();
		}
		else if (current_time.tm_mon == dataB._Get_container()[i].expiry.tm_mon)
		{
			if (current_time.tm_mday >= dataB._Get_container()[i].expiry.tm_mday)
			{
				dataB.pop();
			}
		}
		else if (current_time.tm_year > dataB._Get_container()[i].expiry.tm_year)
		{
			dataB.pop();
		}
		else
		{
			break;
		}

	}

	 //pop type AB expired blood
	for (int i = 0; i < dataAB.size(); i++)
	{
		if (dataAB._Get_container()[i].expiry.tm_mon == 12)
		{
			if (current_time.tm_mon == 1)
			{
				if (current_time.tm_mday > dataAB._Get_container()[i].expiry.tm_mday)
				{
					dataAB.pop();
				}
			}
			else if (current_time.tm_mon > 1 && current_time.tm_mon != 12)
			{
				dataAB.pop();
			}
		}
		else if (current_time.tm_mon > dataAB._Get_container()[i].expiry.tm_mon)
		{
			dataAB.pop();
		}
		else if (current_time.tm_mon == dataAB._Get_container()[i].expiry.tm_mon)
		{
			if (current_time.tm_mday >= dataAB._Get_container()[i].expiry.tm_mday)
			{
				dataAB.pop();
			}
		}
		else if (current_time.tm_year > dataAB._Get_container()[i].expiry.tm_year)
		{
			dataAB.pop();
		}
		else
		{
			break;
		}

	}

	 //pop type O expired blood
	for (int i = 0; i < dataO.size(); i++)
	{
		if (dataO._Get_container()[i].expiry.tm_mon == 12)
		{
			if (current_time.tm_mon == 1)
			{
				if (current_time.tm_mday > dataO._Get_container()[i].expiry.tm_mday)
				{
					dataO.pop();
				}
			}
			else if (current_time.tm_mon > 1 && current_time.tm_mon != 12)
			{
				dataO.pop();
			}
		}
		else if (current_time.tm_mon > dataO._Get_container()[i].expiry.tm_mon)
		{
			dataO.pop();
		}
		else if (current_time.tm_mon == dataO._Get_container()[i].expiry.tm_mon)
		{
			if (current_time.tm_mday >= dataO._Get_container()[i].expiry.tm_mday)
			{
				dataO.pop();
			}
		}
		else if (current_time.tm_year > dataO._Get_container()[i].expiry.tm_year)
		{
			dataA.pop();
		}
		else
		{
			break;
		}

	}

	file.bloodUpdate(dataA,dataB,dataAB,dataO);
}
