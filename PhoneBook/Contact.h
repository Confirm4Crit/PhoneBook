#pragma once
#include <string>
#include <vector>
using namespace std;


class Contact
{
	friend class PhoneBook;
	friend bool compareByCat(Contact &, Contact &);

	void assignNewID(){ lastContactIDUsed++; contactID = lastContactIDUsed; }
public:

private:
	vector<int> companiesAssociatedWithContact;
	int numberOfCompanies;
	string name;
	string number;
	string catagory;
	int contactID;
	static int lastContactIDUsed;

	
};