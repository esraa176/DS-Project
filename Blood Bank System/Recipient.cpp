

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

void Recipient::Recipient_page(int userIndex)
{




}
void Recipient::Update_Data(int user_indx)
{
	char answer;
	int choice;
	int up_age;
	string up_hosp;
	string up_doc;
	
	cin >> answer;
	while (answer != 'N')
	{
		cout << "if you want to update your age press 1: " << endl;
		cout << "if you want to change the hospital press 2: " << endl;
		cout << "if you want to change the name of the doctor press 3:" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cin >> up_age;
			 recipientsList[user_indx].Age = up_age;
		}
		else if (choice == 2)
		{
			cin >> up_hosp;
			recipientsList[user_indx].Hospital = up_hosp;
		}
		else
		{
			cin >> up_doc;
			recipientsList[user_indx].DoctorofTheCase = up_doc;
		}

	}
}
void Recipient::Recipient_Registeration_Page() {
	int Age;
	string Name, Email, Password, Hospital, DoctorofTheCase;
	char Gender;
	string Blood_type;
	cout<< "Enter your gender: ";
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
	recipientsList.push_back(Recipient(Name, Age, Gender, Email, Password, Blood_type, Hospital, DoctorofTheCase));
}
