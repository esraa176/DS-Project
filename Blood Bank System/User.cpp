
#include "User.h"

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
void User:: Update_Data(int)
{
	
}
void User:: Delete_Account()
{
	
}
