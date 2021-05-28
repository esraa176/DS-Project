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
void Recipient::Update_Data(int ID)
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
		}
		else if (choice == 2)
		{
			cin >> up_hosp;
		}
		else
		{
			cin >> up_doc;
		}

	}
}