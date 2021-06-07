#include "Files.h"
fstream adminsFile("admins.txt", ios::in | ios::out | ios::app);
fstream recipientsFile("recipients.txt", ios::in | ios::out | ios::app);
fstream donorsFile("donors.txt", ios::in | ios::out | ios::app);
fstream requestsFile("requests.txt", ios::in | ios::out | ios::app);
fstream typeA("Blood Type-A.txt", ios::in | ios::out | ios::app);
fstream typeB("Blood Type-B.txt", ios::in | ios::out | ios::app);
fstream typeO("Blood Type-O.txt", ios::in | ios::out | ios::app);
fstream typeAB("Blood Type-AB.txt", ios::in | ios::out | ios::app);

void Files::Update_Files(vector <Admin> &adminsList, vector <Recipient> &recipientsList, vector <Donor> &donorsList, queue <Blood> &dataA, queue <Blood> &dataB, queue <Blood> &dataO, queue <Blood>&dataAB, queue <int>& Donor_Requests, int&aID, int& rID, int &dID)
{
	adminUpdate(adminsList, aID);
	resipientUpdate(recipientsList, rID);
	donorUpdate(donorsList, dID);
	bloodUpdate(dataA, dataB, dataO, dataAB);
	requestsUpdate(Donor_Requests);
}

void Files::adminUpdate(vector <Admin>& adminsList, int& aID)
{
	adminsFile.open("admins.txt", ofstream::out | ofstream::trunc);
	for (int i = 0; i < adminsList.size(); i++)
	{
		adminsFile << adminsList[i].ID << " " << adminsList[i].Name << " " << adminsList[i].Age << " ";
		adminsFile << adminsList[i].Gender << " " << adminsList[i].Email << " " << adminsList[i].Password << endl;
	}
	adminsFile.close();
}
void Files::resipientUpdate(vector <Recipient>& recipientsList, int& rID)
{
	recipientsFile.open("recipients.txt", ofstream::out | ofstream::trunc);
	for (int i = 0; i < recipientsList.size(); i++)
	{
		recipientsFile << recipientsList[i].ID << " " << recipientsList[i].Name << " " << recipientsList[i].Age << " ";
		recipientsFile << recipientsList[i].Gender << " " << recipientsList[i].Email << " " << recipientsList[i].Password << " ";
		recipientsFile << recipientsList[i].Blood_type << " " << recipientsList[i].Hospital << " " << recipientsList[i].DoctorofTheCase << endl;
	}
	recipientsFile.close();
}
void Files::donorUpdate(vector <Donor>& donorsList, int& dID)
{
	donorsFile.open("donors.txt", ofstream::out | ofstream::trunc);
	for (int i = 0; i < donorsList.size(); i++)
	{
		donorsFile << donorsList[i].ID << " " << donorsList[i].Name << " " << donorsList[i].Age << " " << donorsList[i].Gender << " ";
		donorsFile << donorsList[i].Email << " " << donorsList[i].Password << " " << donorsList[i].Blood_type << " " << donorsList[i].isDisease << " " << donorsList[i].Other_Disease << " ";
		donorsFile << donorsList[i].Latest_Donation_Date.day << " " << donorsList[i].Latest_Donation_Date.month << " " << donorsList[i].Latest_Donation_Date.year<<" " ;
		donorsFile << donorsList[i].Nxt_Donation_Date.day << " " << donorsList[i].Nxt_Donation_Date.month << " " << donorsList[i].Nxt_Donation_Date.year<< endl;
	}
	donorsFile.close();
}
void Files::bloodUpdate(queue <Blood>& dataA, queue <Blood>& dataB, queue <Blood>& dataO, queue <Blood>& dataAB)
{
	typeA.open("Blood Type-A.txt", ofstream::out | ofstream::trunc);
	for (int i = 0; i < dataA.size(); i++)
	{

		typeA << dataA._Get_container()[i].received.tm_mday << " " << dataA._Get_container()[i].received.tm_mon << " ";
		typeA << dataA._Get_container()[i].received.tm_year << " ";
		typeA << dataA._Get_container()[i].expiry.tm_mday << " ";
		typeA << dataA._Get_container()[i].expiry.tm_mon << " " << dataA._Get_container()[i].expiry.tm_year << endl;
	}
	typeA.close();

	typeB.open("Blood Type-B.txt", ofstream::out | ofstream::trunc);
	for (int i = 0; i < dataB.size(); i++)
	{
		typeB << dataB._Get_container()[i].received.tm_mday << " " << dataB._Get_container()[i].received.tm_mon << " ";
		typeB << dataB._Get_container()[i].received.tm_year << " ";
		typeB << dataB._Get_container()[i].expiry.tm_mday << " ";
		typeB << dataB._Get_container()[i].expiry.tm_mon << " " << dataB._Get_container()[i].expiry.tm_year << endl;

	}
	typeB.close();

	typeO.open("Blood Type-O.txt", ofstream::out | ofstream::trunc);
	for (int i = 0; i < dataO.size(); i++)
	{
		typeO << dataO._Get_container()[i].received.tm_mday << " " << dataO._Get_container()[i].received.tm_mon << " ";
		typeO << dataO._Get_container()[i].received.tm_year << " ";
		typeO << " " << dataO._Get_container()[i].expiry.tm_mday << " ";
		typeO << dataO._Get_container()[i].expiry.tm_mon << " " << dataO._Get_container()[i].expiry.tm_year << endl;

	}
	typeO.close();

	typeAB.open("Blood Type-AB.txt", ofstream::out | ofstream::trunc);
	for (int i = 0; i < dataAB.size(); i++)
	{
		typeAB << dataAB._Get_container()[i].received.tm_mday << " " << dataAB._Get_container()[i].received.tm_mon << " ";
		typeAB << dataAB._Get_container()[i].received.tm_year << " ";
		typeAB << dataAB._Get_container()[i].expiry.tm_mday << " ";
		typeAB << dataAB._Get_container()[i].expiry.tm_mon << " " << dataAB._Get_container()[i].expiry.tm_year << endl;

	}
	typeAB.close();
}
void Files::requestsUpdate(queue <int>& Donor_Requests)
{
	requestsFile.open("requests.txt", ofstream::out | ofstream::trunc);
	for (int i = 0; i < Donor_Requests.size(); i++)
	{
		requestsFile << Donor_Requests._Get_container()[i] << endl;
	}
	requestsFile.close();
}







void Files::Intialize_Vectors_Queues(vector <Admin> &adminsList, vector <Recipient> &recipientsList, vector <Donor> &donorsList, queue <Blood> &dataA, queue <Blood> &dataB, queue <Blood> &dataO, queue <Blood>&dataAB, queue <int>& Donor_Requests, int&aID, int& rID, int &dID)
{

	Admin admin;
	while (adminsFile >> admin.ID >> admin.Name >> admin.Age >> admin.Gender >> admin.Email >> admin.Password)
	{
		adminsList.push_back(admin);
		aID = admin.ID;
	}
	aID++;
	adminsFile.close();

	Recipient r;
	while (recipientsFile >> r.ID >> r.Name >> r.Age >> r.Gender >> r.Email >> r.Password >> r.Blood_type >> r.Hospital >> r.DoctorofTheCase)
	{
		recipientsList.push_back(r);
		rID = r.ID;
	}
	rID++;
	recipientsFile.close();

	Donor d;
	while (donorsFile >> d.ID >> d.Name >> d.Age >> d.Gender >> d.Email >> d.Password >> d.Blood_type >> d.isDisease >> d.Other_Disease >> d.Latest_Donation_Date.day >> d.Latest_Donation_Date.month >> d.Latest_Donation_Date.year>> d.Nxt_Donation_Date.day>>d.Nxt_Donation_Date.month>>d.Nxt_Donation_Date.year)
	{
		donorsList.push_back(d);
		dID = d.ID;
	}
	dID++;
	donorsFile.close();

	while (requestsFile >> d.ID)
	{
		Donor_Requests.push(d.ID);
	}
	requestsFile.close();

	Blood A, B, O, AB;
	while (typeA >> A.received.tm_mday >> A.received.tm_mon >> A.received.tm_year >> A.expiry.tm_mday >> A.expiry.tm_mon >> A.expiry.tm_year)
	{
		dataA.push(A);
	}
	typeA.close();

	while (typeB >> B.received.tm_mday >> B.received.tm_mon >> B.received.tm_year >> B.expiry.tm_mday >> B.expiry.tm_mon >> B.expiry.tm_year)
	{
		dataB.push(B);
	}
	typeB.close();

	while (typeO >> O.received.tm_mday >> O.received.tm_mon >> O.received.tm_year >> O.expiry.tm_mday >> O.expiry.tm_mon >> O.expiry.tm_year)
	{
		dataO.push(O);
	}
	typeO.close();

	while (typeAB >> AB.received.tm_mday >> AB.received.tm_mon >> AB.received.tm_year >> AB.expiry.tm_mday >> AB.expiry.tm_mon >> AB.expiry.tm_year)
	{
		dataAB.push(AB);
	}
	typeAB.close();
}
