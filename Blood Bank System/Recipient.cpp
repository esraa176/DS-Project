#include "Recipient.h"
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include "Blood.h"
#include "Files.h"

using namespace std;
Files fileR;

Recipient::Recipient()
{

}
Recipient::Recipient(string name, int age, char gender, string mail, string pass, string blood_type, string hospital, string doctor, int& rID)
	:User(name, age, gender, mail, pass)
{
	ID = rID;
	rID++;
	Blood_type = blood_type;
	Hospital = hospital;
	DoctorofTheCase = doctor;

}

void Recipient::Recipient_page(int userIndex, vector <Recipient>& recipientsList, queue<Blood>& dataA, queue<Blood>& dataB, queue<Blood>& dataO, queue<Blood>& dataAB, int& rID)
{
	int choice;
	while (true) {
		cout << "                                                             Welcome to Recipient Page: " << endl;
		cout << "Please choose one of these choices: " << endl;
		cout << "press 1 if you want to update your data: " << endl;
		cout << "press 2 if you want to search for the avalibality of blood and make a request for it: " << endl;
		cout << "press 3 if you want to display blood data: " << endl;
		cout << "press 4 if you want to delete your account: " << endl;
		cout << "press 5 if you want to log out: " << endl;
		cin >> choice;
		if (choice == 1)
			Update_Data(userIndex, recipientsList, rID);


		else if (choice == 2)
			Search_for_Blood(recipientsList, userIndex, dataA, dataB, dataO, dataAB, rID);


		else if (choice == 3)
			display_all_blood_data(dataA, dataB, dataO, dataAB);



		else if (choice == 4)
			Delete_Account(userIndex, recipientsList, rID);

		else {
			cout << "thaaannk you: ";
			break;
		}
	}



}
void Recipient::Update_Data(int user_indx, vector <Recipient>& recipientsList, int& rID)
{
	char answer;
	int choice;
	int up_age;
	string up_hosp;
	string up_doc;


	while (true)
	{
		cout << "if you want to update your age press 1: " << endl;
		cout << "if you want to change the hospital press 2: " << endl;
		cout << "if you want to change the name of the doctor press 3:" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "please enter your updated age: ";
			cin >> up_age;
			recipientsList[user_indx].Age = up_age;
			fileR.resipientUpdate(recipientsList, rID);
		}
		else if (choice == 2)
		{
			cout << "please enter your new hosp: ";
			cin >> up_hosp;
			recipientsList[user_indx].Hospital = up_hosp;
			fileR.resipientUpdate(recipientsList, rID);
		}
		else if (choice == 2)
		{
			cout << "please enter the name of your new doc: ";
			cin >> up_doc;
			recipientsList[user_indx].DoctorofTheCase = up_doc;
			fileR.resipientUpdate(recipientsList, rID);
		}
		cout << "Do you want to continue changing your info Y/N: ";
		cin >> answer;
		if (answer == 'n' || answer == 'N')
			break;
	}
}
void Recipient::Recipient_Registeration_Page(vector <Recipient>& recipientsList, queue<Blood>& dataA, queue<Blood>& dataB, queue<Blood>& dataO, queue<Blood>& dataAB, int& rID)
{
	int Age;
	string Name, Email, Password, Hospital, DoctorofTheCase;
	char Gender;
	string Blood_type;
	cout << "Enter your gender: ";
	cin >> Gender;
	cout << "Enter your name: ";
	cin >> Name;
	cout << "Enter your age: ";
	cin >> Age;
	cout << "Enter your mail: ";
	cin >> Email;
	cout << "Enter your password: ";
	cin >> Password;
	cout << "Enter your blood type: ";
	cin >> Blood_type;
	cout << "Enter your hospital: ";
	cin >> Hospital;
	cout << "Enter the name of your doctorcase: ";
	cin >> DoctorofTheCase;
	Recipient reg(Name, Age, Gender, Email, Password, Blood_type, Hospital, DoctorofTheCase, rID);
	recipientsList.push_back(reg);
	fileR.resipientUpdate(recipientsList, rID);
	cout << "\t\t\t\t REGISTERATION SUCCESSFUL! \n\t\t Welcome to Our Blood Bank Management System!\n";
	char recp_2nd_choice;
	cout << "Do you want to make any progress? ";
	while (true) {
		cin >> recp_2nd_choice;
		if (recp_2nd_choice == 'Y' || recp_2nd_choice == 'y') {
			Recipient_page(recipientsList.size() - 1, recipientsList, dataA, dataB, dataO, dataAB, rID);
			break;
		}
		else {
			cout << "Thank you for using our system";
			break;
		}
	}
}



void Recipient::Search_for_Blood(vector <Recipient>& recipientsList, int userIndex, queue<Blood>& dataA, queue<Blood>& dataB, queue<Blood>& dataO, queue<Blood>& dataAB, int&rID) {
	string type;
	char ans;
	bool found = false;
	string av_type;
	while (true) {
		cout << "please enter the blood type you want to search about it's avalibility: ";
		cin >> type;
		if (type == "A") {
			if (dataA.size() > 0) {
				cout << "it is avaliable with " << dataA.size() << " bags" << endl;
				found = true;
				av_type = "A";
			}
			else {
				cout << "sorry blood type A is not avaliable now: " << endl;
			}
		}
		else if (type == "B") {
			if (dataB.size() > 0) {
				cout << "it is avaliable with " << dataA.size() << " bags" << endl;
				found = true;
				av_type = "B";
			}
			else {
				cout << "sorry blood type B is not avaliable now: " << endl;
			}
		}
		else if (type == "AB") {
			if (dataB.size() > 0) {
				cout << "it is avaliable with " << dataAB.size() << " bags" << endl;
				found = true;
				av_type = "AB";
			}
			else {
				cout << "sorry blood type AB is not avaliable now: " << endl;
			}
		}
		else if (type == "O") {
			if (dataB.size() > 0) {
				cout << "it is avaliable with " << dataO.size() << " bags" << endl;
				found = true;
				av_type = "O";
			}
			else {
				cout << "sorry blood type O is not avaliable now: " << endl;
			}
		}
		if (recipientsList.at(userIndex).Blood_type == "AB") {
			cout << "if do you want to search on another blood type as your blood type can accept from any blood types press Y if you don't want press N " << endl;
			cin >> ans;
			if (ans == 'n' || ans == 'N')
				break;

		}
		else {
			break;
		}

	}
	if (found == true) {
		cout << "Do you want to make a request to take this blood type? Y/N :" << endl;
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			Request_Blood(userIndex, recipientsList, av_type, dataA, dataB, dataO, dataAB, rID);
		}
	}
	else {
		cout << "Thank you: " << endl;
	}


}

void Recipient::Request_Blood(int userIndex, vector <Recipient>& recipientsList, string av_type, queue<Blood>& dataA, queue<Blood>& dataB, queue<Blood>& dataO, queue<Blood>& dataAB, int& rID) {
	string hosp;
	char ans;
	cin >> ans;
	if (av_type == "A") {
		dataA.pop();
		fileR.resipientUpdate(recipientsList, rID);
	}
	else if (av_type == "B") {
		dataB.pop();
		fileR.resipientUpdate(recipientsList, rID);
	}
	else if (av_type == "O") {
		dataO.pop();
		fileR.resipientUpdate(recipientsList, rID);
	}
	else {
		dataAB.pop();
		fileR.resipientUpdate(recipientsList, rID);
	}
	cout << "Do you want the blood to be delivered to your current hospital or another hospital? " << endl;
	if (ans == 'y' || ans == 'Y') {
		cout << "please enter the name of the hospital: " << endl;
		cin >> hosp;
		cout << "successfully your blood will be delivered to " + hosp << endl;
	}
	else {
		cout << "successfully your blood will be delivered to " + recipientsList.at(userIndex).Hospital << endl;
	}
	cout << "your request is successfully accepted: " << endl;
}


void Recipient::Delete_Account(int user_indx, vector <Recipient>& recipientsList, int&rID) {
	recipientsList.erase(next(recipientsList.begin(), user_indx));
	fileR.resipientUpdate(recipientsList, rID);


}

void Recipient::display_all_blood_data(queue<Blood>& dataA, queue<Blood>& dataB, queue<Blood>& dataO, queue<Blood>& dataAB) {

	cout << "Blood type A : " << endl;
	cout << "Blood quantity is : " << dataA.size() << " bags (1 Liter\\bag)" << endl << endl;
	for (int i = 0; i < dataA.size(); i++)
	{
		cout << "\t\tBag number " << i + 1 << ": " << endl;
		cout << "\t\tReceived date: " << dataA._Get_container()[i].received.tm_mday << "/" << dataA._Get_container()[i].received.tm_mon << "/" << dataA._Get_container()[i].received.tm_year << endl;
		cout << "\t\tExpiry date: " << dataA._Get_container()[i].expiry.tm_mday << "/" << dataA._Get_container()[i].expiry.tm_mon << "/" << dataA._Get_container()[i].expiry.tm_year << endl;
		cout << "\t\t----------------" << endl;
	}
	cout << "---------------------------------------------------------------" << endl;
	cout << "Blood type B : " << endl;
	cout << "Blood quantity is : " << dataB.size() << " bags (1 Liter\\bag) " << endl << endl;
	for (int i = 0; i < dataB.size(); i++)
	{
		cout << "\t\tBag number " << i + 1 << ": " << endl;
		cout << "\t\tReceived date: " << dataB._Get_container()[i].received.tm_mday << "/" << dataB._Get_container()[i].received.tm_mon << "/" << dataB._Get_container()[i].received.tm_year << endl;
		cout << "\t\tExpiry date: " << dataB._Get_container()[i].expiry.tm_mday << "/" << dataB._Get_container()[i].expiry.tm_mon << "/" << dataB._Get_container()[i].expiry.tm_year << endl;
		cout << "\t\t----------------" << endl;
	}
	cout << "---------------------------------------------------------------" << endl;
	cout << "Blood type AB : " << endl;
	cout << "Blood quantity is : " << dataAB.size() << " bags (1 Liter\\bag)" << endl << endl;
	for (int i = 0; i < dataAB.size(); i++)
	{
		cout << "\t\tBag number " << i + 1 << ": " << endl;
		cout << "\t\tReceived date: " << dataAB._Get_container()[i].received.tm_mday << "/" << dataAB._Get_container()[i].received.tm_mon << "/" << dataAB._Get_container()[i].received.tm_year << endl;
		cout << "\t\tExpiry date: " << dataAB._Get_container()[i].expiry.tm_mday << "/" << dataAB._Get_container()[i].expiry.tm_mon << "/" << dataAB._Get_container()[i].expiry.tm_year << endl;
		cout << "\t\t----------------" << endl;
	}
	cout << "---------------------------------------------------------------" << endl;
	cout << "Blood type O : " << endl;
	cout << "Blood quantity is : " << dataO.size() << " bags (1 Liter\\bag)" << endl << endl;
	for (int i = 0; i < dataO.size(); i++)
	{
		cout << "Bag number " << i + 1 << ": " << endl;
		cout << "Received date: " << dataO._Get_container()[i].received.tm_mday << "/" << dataO._Get_container()[i].received.tm_mon << "/" << dataO._Get_container()[i].received.tm_year << endl;
		cout << "Expiry date: " << dataO._Get_container()[i].expiry.tm_mday << "/" << dataO._Get_container()[i].expiry.tm_mon << "/" << dataO._Get_container()[i].expiry.tm_year << endl;
		cout << "\t\t----------------" << endl;
	}
}
