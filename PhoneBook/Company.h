#pragma once
#include <string>
#include <vector>

using namespace std;

class Company
{
public:
	friend class PhoneBook;

	string getCompanyName(){ return companyName; }
	void setCompanyName(string s){ companyName = s; }
	
	string getCompanyAddress(){ return companyAddress; }
	void setCompanyAddressr(string s){ companyAddress = s; }
	
	string getCompanyCatagory(){ return companyCatagory; }
	void setCompanyCatagory(string s){ companyCatagory = s; }

	void assignNewCompanyID(){ lastCompanyIDUsed++; companyID = lastCompanyIDUsed; }

	friend bool companyCompareByCat(Company &, Company &);
	


private:
	vector<int> associatedContacts;
	string companyName;
	string companyAddress;
	string companyCatagory;

	int companyID;
	static int lastCompanyIDUsed;
	int numberOfContacts;
};