#include<string>
#include<iostream>

using namespace std;
class User
{
public:
	int ID, Age;
	string Name, Email, Password;
	char Gender;

public:
	User(int, string, int, char, string ,string);
	User();

	void Update_Data(int);
	void Delete_Account();
};
