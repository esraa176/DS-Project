#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include "Admin.h"
#include "Donor.h"
#include "Recipient.h"
#include "Blood.h"
using namespace std;
class Files
{
public:
	void Update_Files(vector <Admin> &, vector <Recipient> &, vector <Donor> &, queue <Blood> &, queue <Blood> &, queue <Blood> &, queue <Blood>&, queue <int>&, int&, int&, int &);
	void Intialize_Vectors_Queues(vector <Admin> &, vector <Recipient> &, vector <Donor> &, queue <Blood> &, queue <Blood> &, queue <Blood> &, queue <Blood>&, queue <int>&, int&, int&, int &);
	void adminUpdate(vector <Admin> &,int&);
	void resipientUpdate(vector <Recipient> &, int&);
	void donorUpdate(vector <Donor> &, int&);
	void bloodUpdate(queue <Blood> &, queue <Blood> &, queue <Blood> &, queue <Blood>&);
	void requestsUpdate(queue <int>&);
};
