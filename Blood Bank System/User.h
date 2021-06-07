#pragma once
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
	User(string, int, char, string, string);
	User();
};
