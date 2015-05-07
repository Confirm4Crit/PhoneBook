#pragma once
#include "Contact.h"
#include <vector>
#include "Company.h"

using namespace std;

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	string addContact(string name, string number, string catagory);
	string display();
	int size(){ return vContact.size(); }
	string removeContact(string name);
	string clearContacts(){ vContact.clear(); return "Contacts cleared."; }
	string displayByCat();
	string saveBook(string filename);
	string loadBook(string filename);

	string addCompany(string companyName, string companyAddress, string companyCatagory);
	string removeCompany(string companyID);
	string displayCompanies();
	string displayCompaniesByCat();
	string saveCompanies(string filename);
	string loadCompanies(string filename);
	string clearCompanies(){ vCompany.clear(); return "Companies cleared."; }
	int companiessize(){ return vCompany.size(); }

	string associatePersonWithCompany(int contactID, int companyID);
	string getCompaniesAssociatedWithContact(int contactID);
	string getContactAssociatedWithCompany(int comanyID);

	string addRandPerson(int count);
	string addRandCompanies(int count);

	string saveAssociations();
	string loadAssociations();



private:
	vector<Contact> vContact;
	vector<Company> vCompany;

	Contact & getContactByID(int id);
	Company & getCompanyByID(int id);

};