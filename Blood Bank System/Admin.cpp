#include"Admin.h"
#include<iostream>
#include<string>
#include"Donor.h"
using namespace std;

Admin::Admin()
{

}
Admin::Admin(string name, int age, char gender, string email, string password)
{
	Name = name;
	Age = age;
	Gender = gender;
	Email = email;
	Password = password;
	ID = Admin_count;
	Admin_count++;
}

void Admin::Admin_page(int userIndex)
{
	

}
void Admin::validateRequests()
{

}

void Admin::addDonors()
{

}

