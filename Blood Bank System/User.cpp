
#include "User.h"
#include"Admin.h"
#include<iostream>
#include<string>
#include"Donor.h"
#include"Recipient.h"

using namespace std;

User::User()
{

}

User::User(int id,string name, int age, char gender, string mail, string pass)
{
	ID = id;
	Name = name;
	Email = mail;
	Password = pass;
	Age = age;
	Gender = gender;
}
void Update_Data(int)
{

}
void Delete_Account()
{

}
