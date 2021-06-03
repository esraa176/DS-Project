
#include "User.h"

using namespace std;

User::User()
{

}

User::User( string name, int age, char gender, string mail, string pass)
{
	Name = name;
	Email = mail;
	Password = pass;
	Age = age;
	Gender = gender;
}
void User::Update_Data(int)
{

}
void User::Delete_Account()
{

}
