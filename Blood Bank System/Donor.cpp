#include "Donor.h"


using namespace std;


Donor::Donor()
{

}
Donor::Donor(string name, int age, char gender, string mail, string pass,string blood_type, string disease, Date latest_donation_date)
{
	ID = Donor_count;
	//User( ID,  name,  age,  gender,  mail,  pass);
	Donor_count++;
	Blood_type = blood_type;
	Disease = disease;
	Latest_Donation_Date = latest_donation_date;
}
void Donor::Donor_page(int userIndex)
{


}
void Donor::Donation_Request(int indx)
{
	

}
void Donor::Update_Data(int New_Age)
{

}
