#include "Recipient.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

Recipient::Recipient()
{

}
Recipient::Recipient(string name, int age, char gender, string mail, string pass, string blood_type, string hospital, string doctor) {
	ID = Reciepient_count;
	Reciepient_count++;
	Name = name;
	Email = mail;
	Password = pass;
	Age = age;
	Gender = gender;
	Blood_type = blood_type;
	Hospital = hospital;
	DoctorofTheCase = doctor;

}

void Recipient::Recipient_page(int userIndex, vector <Recipient>& recipientsList)
{
	int choice;
	while (true) {
		cout << "                                                             Welcome to Recipient Page: " << endl;
		cout << "Please choose one of these choices: " << endl;
		cout << "press 1 if you want to update your data: " << endl;
		cout << "press 2 if you want to search for the avalibality of blood: " << endl;
		cout << "press 3 if you want to display blood data: " << endl;
		cout << "press 4 if you want to make a request for a blood:  " << endl;
		cout << "press 5 if you want to delete your account: " << endl;
		cout << "press 6 if you want to log out: " << endl;
		cin >> choice;
		if (choice == 1)
			Update_Data(userIndex, recipientsList);


		else if (choice == 2)
			Search_for_Blood();


		else if (choice == 3)
			display_all_blood_data();

		else if (choice == 4)
			Request_Blood();

		else if (choice == 5)
			Delete_Account(userIndex, recipientsList);

		else {
			cout << "thaaannk you: ";
			break;
		}
	}
	


}
void Recipient::Update_Data(int user_indx, vector <Recipient>& recipientsList)
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
		}
		else if (choice == 2)
		{
			cout << "please enter your new hosp: ";
			cin >> up_hosp;
			recipientsList[user_indx].Hospital = up_hosp;
		}
		else if(choice==2)
		{
			cout << "please enter the name of your new doc: ";
			cin >> up_doc;
			recipientsList[user_indx].DoctorofTheCase = up_doc;
		}
		cout << "Do you want to continue changing your info Y/N: ";
		cin >> answer;
		if (answer == 'n' || answer == 'N')
			break;
	}
}
void Recipient::Recipient_Registeration_Page(vector <Recipient>& recipientsList) {
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
	Recipient reg(Name, Age, Gender, Email, Password, Blood_type, Hospital, DoctorofTheCase);
	recipientsList.push_back(reg);

	cout << "\t\t\t\t REGISTERATION SUCCESSFUL! \n\t\t Welcome to Our Blood Bank Management System!\n";
	char recp_2nd_choice;
	cout << "Do you want to make any progress? ";
	while (true) {
		cin >> recp_2nd_choice;
		if (recp_2nd_choice == 'Y' || recp_2nd_choice == 'y') {
			Recipient_page(recipientsList.size() - 1, recipientsList);
			break;
		}
		else {
			cout << "Thank you for using our system";
			break;
		}
	}
}
void Recipient::Delete_Account(int user_indx, vector <Recipient>& recipientsList){
	  recipientsList.erase(user_indx);
		
}
void Recipient::Search_for_Blood() {

}
void Recipient::display_all_blood_data() {
		cout << "Blood type is : " <<"A" << endl;
		cout << "Blood quantity is : " << A.quantity << endl;
		cout << "Recieved date of blood is: " << A.recieved.day << "/" << A.recieved.month << "/" << A.recieved.year << endl;		
		cout << "expiry date of blood is: " << A.expiry.day << "/" << A.expiry.month << "/" << A.expiry.year << endl;
		cout << "Blood type is : " << "B" << endl;
		cout << "Blood quantity is : " << B.quantity << endl;
		cout << "Recieved date of blood is: " << B.recieved.day <<"/"<< B.recieved.month<<"/"<< B.recieved.year<< endl;
		cout << "expiry date of blood is: " << B.expiry.day << "/" << B.expiry.month << "/" << B.expiry.year << endl;
		cout << "Blood type is : " << "AB" << endl;
		cout << "Blood quantity is : " << AB.quantity << endl;
		cout << "Recieved date of blood is: " << AB.recieved.day << "/" << AB.recieved.month << "/" << AB.recieved.year << endl;		
		cout << "expiry date of blood is: " << AB.expiry.day << "/" << AB.expiry.month << "/" << AB.expiry.year << endl;
		cout << "Blood type is : " << "O" << endl;
		cout << "Blood quantity is : " << O.quantity << endl;
		cout << "Recieved date of blood is: " << O.recieved.day << "/" << O.recieved.month << "/" << O.recieved.year << endl;
		cout << "expiry date of blood is: " << O.expiry.day<<"/"<< O.expiry.month<<"/"<< O.expiry.year << endl;
}
void Recipient::Request_Blood() {

}
