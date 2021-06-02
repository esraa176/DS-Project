#include "Admin.h"
#include <iostream>
#include <string>
#include <vector>
#include "Donor.h"
#include "Recipient.h"
#include <queue>
#include "Blood.h"


using namespace std;

Admin::Admin()
{

}
Admin::Admin(string name, int age, char gender, string email, string password, int& aID)//:User(name,age,gender,email,password)
{
	Name = name;
	Age = age;
	Gender = gender;
	Email = email;
	Password = password;
	ID = aID;
	aID++;
}

void Admin::Admin_page(int userIndex, vector <Admin>& adminsList, vector <Donor>& donorsList, vector <Recipient>& recipientsList, queue<int>& Donor_Requests, queue<Blood>& dataA, queue<Blood>& dataB, queue<Blood>& dataO, queue<Blood>& dataAB, int& aID, int& rID, int& dID)
{
	cout << "\t\t Enter 1 to display & validate donor's requests." << endl;
	cout << "\t\t Enter 2 to Insert/Update/Delete the quantity of blood." << endl;
	cout << "\t\t Enter 3 to Insert/Update/Delete data of users." << endl;
	cout << "\t\t Enter 4 to exit this menu." << endl;
	int choice;
	while (true)
	{
		cin >> choice;
		if (choice == 1)
		{
			Display_requests(donorsList, Donor_Requests);
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
					insertUser(adminsList, donorsList, recipientsList, Donor_Requests, dataA, dataB, dataO, dataAB, aID, rID, dID);
					break;
				}
				else if (choice2 == 2)
				{
					updateUser(adminsList, donorsList, recipientsList);
					break;
				}
				else if (choice2 == 3)
				{
					deleteUser(adminsList, donorsList, recipientsList);
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
		else if (choice == 4)
		{
			return;
		}
		else
		{
			cout << "Invalid Choice, Please Enter a number(1, 2, 3 or 4)\n";
		}

	}
}


void Admin::Admin_Register(vector <Admin>& adminsList, vector <Donor>& donorsList, vector <Recipient>& recipientsList, queue<int>& Donor_Requests, queue<Blood>& dataA, queue<Blood>& dataB, queue<Blood>& dataO, queue<Blood>& dataAB, int& aID, int& rID, int& dID)
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
	Admin reg(name, age, gender, email, pass, aID);
	adminsList.push_back(reg);
	cout << "\t\t\t\t REGISTERATION SUCCESSFUL! \n\t\t Welcome to Our Blood Bank Management System!\n";
	Admin_page(adminsList.size() - 1, adminsList, donorsList, recipientsList, Donor_Requests, dataA, dataB, dataO, dataAB, aID, rID, dID);
}

void Admin::insertUser(vector <Admin>& adminsList, vector <Donor>& donorsList, vector <Recipient>& recipientsList, queue<int>& Donor_Requests, queue<Blood>& dataA, queue<Blood>& dataB, queue<Blood>& dataO, queue<Blood>& dataAB, int& aID, int&rID, int&dID)
{
	cout << "Enter the number of your choice:\n" << endl;
	cout << "1-Insert admin." << endl;
	cout << "2-Insert donor." << endl;
	cout << "3-Insert recipient." << endl;
	int choice;
	cin >> choice;
	while (true)
	{
		if (choice == 1)
		{
			Admin reg;
			reg.Admin_Register(adminsList, donorsList, recipientsList, Donor_Requests, dataA, dataB, dataO, dataAB, aID, rID, dID);
			cout << "Insertion is successfully done." << endl;
			cout << "_________________________________" << endl;
			break;
		}
		else if (choice == 2)
		{
			Donor reg;
			reg.Donor_Registeration(donorsList, Donor_Requests, dID);
			cout << "Insertion is successfully done." << endl;
			cout << "_________________________________" << endl;
			break;
		}
		else if (choice == 3)
		{
			Recipient reg;
			reg.Recipient_Registeration_Page(recipientsList, dataA, dataB, dataO, dataAB, rID);
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
void Admin::deleteUser(vector <Admin>& adminsList, vector <Donor>& donorsList, vector <Recipient>& recipientsList)
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
void Admin::updateUser(vector <Admin>& adminsList, vector <Donor>& donorsList, vector <Recipient>& recipientsList)
{
	cout << "Enter the number of your choice:" << endl;
	cout << "1-Update data of an admin." << endl;
	cout << "2-Update data of a donor." << endl;
	cout << "3-Update data of a recipient." << endl;
	int choice, choice2;
	char answer;
	cin >> choice;
	cout << "Please enter user's ID.\n";
	int id;
	cin >> id;
	int age;
	string name, pass;
	bool isFound = false;
	if (choice == 1)
	{
		while (true)
		{
			for (int i = 0; i < adminsList.size(); i++)
			{
				if (id == adminsList[i].ID)
				{
					isFound = true;
					while (true)
					{
						cout << "press 1 to update the name." << endl;
						cout << "press 2 to update the age." << endl;
						cout << "press 3 to update the password." << endl;
						cin >> choice2;
						if (choice2 == 1)
						{
							cout << "enter the new name: "; cin >> name;
							adminsList[i].Name = name;
						}
						else if (choice2 == 2)
						{
							cout << "enter the new age: "; cin >> age;
							adminsList[i].Age = age;
						}
						else if (choice2 == 3)
						{
							cout << "enter the new password: "; cin >> pass;
							adminsList[i].Password = pass;

						}
						else
						{
							cout << "Invalid Choice, Please Enter a number(1, 2 or 3)\n";
							continue;
						}
						cout << "Do you want to continue updating data of this admin? (y/n) "; cin >> answer;
						if (answer == 'N' || answer == 'n')
						{
							break;
						}
					}

				}
			}
			if (!isFound)
			{
				cout << "Incorrect ID, Please try again." << endl;
				cin >> id;
			}
		}
	}
	if (choice == 2)
	{
		while (true)
		{
			for (int i = 0; i < donorsList.size(); i++)
			{
				if (id == donorsList[i].ID)
				{
					isFound = true;
					while (true)
					{
						cout << "press 1 to update the name." << endl;
						cout << "press 2 to update the age." << endl;
						cout << "press 3 to update the password." << endl;
						cin >> choice2;
						if (choice2 == 1)
						{
							cout << "enter the new name: "; cin >> name;
							donorsList[i].Name = name;
						}
						else if (choice2 == 2)
						{
							cout << "enter the new age: "; cin >> age;
							donorsList[i].Age = age;
						}
						else if (choice2 == 3)
						{
							cout << "enter the new password: "; cin >> pass;
							donorsList[i].Password = pass;
						}
						else
						{
							cout << "Invalid Choice, Please Enter a number(1, 2 or 3)\n";
							continue;
						}

						cout << "Do you want to continue updating data of this donor? (y/n) "; cin >> answer;
						if (answer == 'N' || answer == 'n')
						{
							break;
						}
					}

				}
			}
			if (!isFound)
			{
				cout << "Incorrect ID, Please try again." << endl;
				cin >> id;
			}
		}
	}
	if (choice == 2)
	{
		while (true)
		{
			for (int i = 0; i < recipientsList.size(); i++)
			{
				if (id == recipientsList[i].ID)
				{
					isFound = true;
					while (true)
					{
						cout << "press 1 to update the name." << endl;
						cout << "press 2 to update the age." << endl;
						cout << "press 3 to update the password." << endl;
						cin >> choice2;
						if (choice2 == 1)
						{
							cout << "enter the new name: "; cin >> name;
							recipientsList[i].Name = name;
						}
						else if (choice2 == 2)
						{
							cout << "enter the new age: "; cin >> age;
							recipientsList[i].Age = age;
						}
						else if (choice2 == 3)
						{
							cout << "enter the new password: "; cin >> pass;
							recipientsList[i].Password = pass;
						}
						else
						{
							cout << "Invalid Choice, Please Enter a number(1, 2 or 3)\n";
							continue;
						}
						cout << "Do you want to continue updating data of this recipient? (y/n) "; cin >> answer;
						if (answer == 'N' || answer == 'n')
						{
							break;
						}
					}
				}
			}
			if (!isFound)
			{
				cout << "Incorrect ID, Please try again." << endl;
				cin >> id;
			}
		}
	}
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
void Admin::displayData(int userIndex, vector <Admin>& adminsList, vector <Donor>& donorList, vector <Recipient>& recipientList, char userType)
{
	cout << "All data of user with ID: ";
	if (userType == 'A')
	{
		cout << adminsList[userIndex].ID << endl;
		cout << "Name: " << adminsList[userIndex].Name << endl;
		cout << "Age: " << adminsList[userIndex].Age << endl;
		cout << "Gender: " << adminsList[userIndex].Gender << endl;
		cout << "Email: " << adminsList[userIndex].Email << endl;
		cout << "Password: " << adminsList[userIndex].Password << endl;
	}
	else if (userType == 'D')
	{
		cout << donorList[userIndex].ID << endl;
		cout << "Name: " << donorList[userIndex].Name << endl;
		cout << "Age: " << donorList[userIndex].Age << endl;
		cout << "Gender: " << donorList[userIndex].Gender << endl;
		cout << "Email: " << donorList[userIndex].Email << endl;
		cout << "Password: " << donorList[userIndex].Password << endl;
		cout << "Blood Type: " << donorList[userIndex].Blood_type << endl;
		cout << "If she/he suffers from any disease(blood pressure disorders, thyroid disease, diabetes, cancer, heart disorders, hepatitis): " << donorList[userIndex].isDisease << endl;
		cout << "If she/he suffers from any other disease or take any medicine: " << donorList[userIndex].Other_Disease << endl;
		cout << "Latest Donation Date: " << donorList[userIndex].Latest_Donation_Date.tm_mday << "/" << donorList[userIndex].Latest_Donation_Date.tm_mon << "/" << donorList[userIndex].Latest_Donation_Date.tm_year << endl;
	}
	else
	{
		cout << recipientList[userIndex].ID << endl;
		cout << "Name: " << recipientList[userIndex].Name << endl;
		cout << "Age: " << recipientList[userIndex].Age << endl;
		cout << "Gender: " << recipientList[userIndex].Gender << endl;
		cout << "Email: " << recipientList[userIndex].Email << endl;
		cout << "Password: " << recipientList[userIndex].Password << endl;
		cout << "Blood Type: " << recipientList[userIndex].Blood_type << endl;
		cout << "Hospital: " << recipientList[userIndex].Hospital << endl;
		cout << "Doctor of the Case: " << recipientList[userIndex].DoctorofTheCase << endl;
	}
}
void Admin::bloodDate()
{
	tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int day = newtime.tm_mday;

	int Month = 1 + newtime.tm_mon;

	int year = 1900 + newtime.tm_year;
}
void Admin::validateRequests(vector <Donor>& donorsList, queue <int>& Donor_Requests)
{
	int indx;
	char ch;
	cout << "Do you want to validate the requests?(y/n)\n";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{

		while (!Donor_Requests.empty())
		{
			int id = Donor_Requests.front();
			for (int i = 0; i < donorsList.size(); i++)
			{
				if (donorsList[i].ID == id)
				{
					indx = i;
					break;
				}
			}
			if (donorsList[indx].Age >= 17 && donorsList[indx].Age <= 60 && donorsList[indx].isDisease == false && donorsList[indx].Other_Disease == false)
			{
				donorsList[indx].Validated_Donor = true;
			}
			else
			{
				donorsList[indx].Validated_Donor = false;
			}

			Donor_Requests.pop();
		}
	}
}
void Admin::Display_requests(vector <Donor>& donorsList, queue <int>& Donor_Requests)
{
	if (Donor_Requests.size() == 0)
	{
		cout << "There is no request available now\n";
	}
	else
	{

		for (int i = 0; i < Donor_Requests.size(); i++)
		{

			for (int j = 0; j < donorsList.size(); j++)
			{
				if (Donor_Requests._Get_container()[i] == donorsList[j].ID)
				{
					if (donorsList[j].isDisease == false)
					{
						cout << "Donor's ID : " << donorsList[j].ID << "\t" << "The User satisfies Donation rules\n";
						break;
					}
					else
					{
						cout << "Donor's ID : " << donorsList[j].ID << "\t" << "The User Doesn't satisfy Donation rules\n";
						break;
					}
				}

			}
		}
		validateRequests(donorsList, Donor_Requests);
	}

}
