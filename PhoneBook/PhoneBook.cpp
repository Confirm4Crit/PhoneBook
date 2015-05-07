
#include <algorithm>
#include <fstream>
#include "Company.h"
#include "PhoneBook.h"
#include "misc.h"


using namespace std;
PhoneBook::PhoneBook()
{
	loadBook("def");
	loadCompanies("def");
}
PhoneBook::~PhoneBook()
{
	saveBook("def");
	saveCompanies("def");
}

string PhoneBook::addContact(string name, string number, string catagory)
{
	Contact newContact;
	newContact.name = name;
	newContact.number = number;
	newContact.catagory = catagory; 
	newContact.assignNewID();

	vContact.push_back(newContact);
	return "Contact has been added";
}

string PhoneBook::display()
{
	if (vContact.size() != 0)
	{

		string result;
		result += padRight("Id", '.', 10);
		result += padRight("Name", '.', 20);
		result += padRight("Number", '.', 20);
		result += padRight("Catagory", '.', 20) + "\n";
		result += padRight("", '-', 70) + "\n";

		vector<Contact>::iterator iter;

		iter = vContact.begin();

		while (iter != vContact.end())
		{
			result += padRight(intToString((*iter).contactID), ' ', 8) + "  ";
			result += padRight((*iter).name, ' ', 20);
			result += padRight((*iter).number, ' ', 20);
			result += padRight((*iter).catagory, ' ', 20) + "\n";
			result += "Companies: " + getCompaniesAssociatedWithContact(((*iter).contactID));
			iter++;
		}
		return result;
	}
	else
	{
		return "Your phone book is empty!";
	}
}

string PhoneBook::displayByCat()
{
	sort(vContact.begin(), vContact.end(), compareByCat);
	return display();
}

string PhoneBook::removeContact(string name)
{

	vector<Contact>::iterator iter;

	iter = vContact.begin();

	while (iter != vContact.end())
	{
		if ((*iter).name == name)
		{
			iter = vContact.erase(iter);
		}
		else ++iter;
	}

	return "Contact deleated!";
}


string PhoneBook::saveBook(string filename)
{
	ofstream fout;
	fout.open(filename + ".persons.txt");
	fout << Contact::lastContactIDUsed << endl;
	vector<Contact>::iterator iter;

	
	iter = vContact.begin();
	
	while (iter != vContact.end())
	{
		fout << (*iter).contactID<<' ';
		fout << (*iter).name << ';';
		fout << (*iter).number << ';';
		fout << (*iter).catagory << ';';
		(*iter).numberOfCompanies = (*iter).companiesAssociatedWithContact.size();
		if (((*iter).numberOfCompanies) != 0)
		{
			int numCompCheck = 1;
			fout << (*iter).numberOfCompanies << ';';
			vector<int>::iterator cIter;
			cIter = (*iter).companiesAssociatedWithContact.begin();
			while (cIter != (*iter).companiesAssociatedWithContact.end())
			{
				if (numCompCheck != (*iter).numberOfCompanies)
				{
					fout << (*cIter) << ';';
					cIter++;
				}
				else
					fout << (*cIter);
					cIter++;
				
			}
			fout << endl;
		}
		else  fout << "0" << endl;
		iter++;
	}	
	return "Phone book saved";
}

string PhoneBook::loadBook(string filename)
{
		ifstream fin;
		fin.open(filename + ".persons.txt");
		if (fin.fail())return "File not found.";
		clearContacts();
		string inputLine;
		getline(fin, inputLine);
		Contact::lastContactIDUsed = stringToInt(inputLine);
		while (!fin.eof())
		{
			
			getline(fin, inputLine);
			vector<string> token = tokenize(inputLine);
			if (token.size() > 1)
			{

				Contact iContact;

				iContact.contactID = stringToInt(token[0]);
				iContact.name = token[1];
				iContact.number = token[2];
				iContact.catagory = token[3];
				iContact.numberOfCompanies = stringToInt(token[4]);
				if (iContact.numberOfCompanies != 0)
				{
					int cNum = token.size() - 5;
					//int x = token.size() - cNum;

					for (int i = token.size() - cNum; i < token.size(); i++)
					{
						iContact.companiesAssociatedWithContact.push_back(stringToInt(token[i]));
					}

				}
				vContact.push_back(iContact);
			}
			
			
		}
			

			
			
			

	return "Phone book loaded!";
}
Contact & PhoneBook::getContactByID(int key)
{
	vector<Contact>::iterator iter;

	for (iter = vContact.begin(); iter != vContact.end(); iter++)
	{
		if ((*iter).contactID == key)
		{
			return (*iter);
		}
	}
	//throw (string) "Contact ID " + intToString(key) + " does not currently exist";
}



string PhoneBook::addCompany(string name, string address, string catagory)
{
	Company newCompany;
	newCompany.setCompanyName(name);
	newCompany.setCompanyAddressr(address);
	newCompany.setCompanyCatagory(catagory);
	newCompany.assignNewCompanyID();
	vCompany.push_back(newCompany);
	return "Company added.";
}

string PhoneBook::removeCompany(string name)
{
	vector<Company>::iterator iter;

	iter = vCompany.begin();

	while (iter != vCompany.end())
	{
		if ((*iter).companyName == name)
		{
			iter = vCompany.erase(iter);
		}
		else ++iter;
	}

	return "Company deleated!";
	
}

string PhoneBook::displayCompanies()
{

	if (vCompany.size() != 0)
	{
		string result;
		result += padRight("Id", '.', 10);
		result += padRight("Company", '.', 20);
		result += padRight("Address", '.', 20);
		result += padRight("Catagory", '.', 20) + "\n";
		result += padRight("", '-', 70) + "\n";

		vector<Company>::iterator iter;

		iter = vCompany.begin();

		while (iter != vCompany.end())
		{
			result += padRight(intToString((*iter).companyID), ' ', 8) + "  ";
			result += padRight((*iter).companyName, ' ', 20);
			result += padRight((*iter).companyAddress, ' ', 20);
			result += padRight((*iter).companyCatagory, ' ', 20) + "\n";
			result += "Contacts: " + getContactAssociatedWithCompany((*iter).companyID);
		
			iter++;
		}

		return result;
	}
	else
	{
		return "Your company list is empty!";
	}
	

}

string PhoneBook::displayCompaniesByCat()
{
	sort(vCompany.begin(), vCompany.end(), companyCompareByCat);
	return displayCompanies();
}

string PhoneBook::saveCompanies(string filename)
{
	ofstream fout;
	fout.open(filename + ".companies.txt");
	fout << Company::lastCompanyIDUsed << endl;
	vector<Company>::iterator iter;

	
	iter = vCompany.begin();
	while (iter != vCompany.end())
	{
		fout << (*iter).companyID << ' ';
		fout << (*iter).companyName << ';';
		fout << (*iter).companyAddress << ';';
		fout << (*iter).companyAddress << ';';

		(*iter).numberOfContacts = (*iter).associatedContacts.size();

		if (((*iter).numberOfContacts) != 0)
		{
			int numConCheck = 1;
			fout << (*iter).numberOfContacts << ';';
			vector<int>::iterator cIter;
			cIter = (*iter).associatedContacts.begin();
			while (cIter != (*iter).associatedContacts.end())
			{
				if (numConCheck != (*iter).numberOfContacts)
				{
					fout << (*cIter) << ';';
					cIter++;
				}
				else
					fout << (*cIter);
				cIter++;
			}
			fout << endl;
		}
		else fout << "0" << endl;
		iter++;
	}
	
	
	return "Company book saved";
}

string PhoneBook::loadCompanies(string filename)
{
	
	ifstream fin;
	fin.open(filename + ".companies.txt");
	if (fin.fail())return "File not found.";
	clearCompanies();
	string inputLine;
	getline(fin, inputLine);
	Company::lastCompanyIDUsed = stringToInt(inputLine);
	while (!fin.eof())
	{

		getline(fin, inputLine);
		vector<string> token = tokenize(inputLine);

		if (token.size() > 1)
		{
			Company iCompany;

			iCompany.companyID = stringToInt(token[0]);
			iCompany.companyName = token[1];
			iCompany.companyAddress = token[2];
			iCompany.companyCatagory = token[3];
			iCompany.numberOfContacts = stringToInt(token[4]);
			if (iCompany.numberOfContacts != 0)
			{
				int cNum = token.size() - 5;
				for (int i = token.size() - cNum; i < token.size(); i++)
				{
					iCompany.associatedContacts.push_back(stringToInt(token[i]));
				}
			}
			vCompany.push_back(iCompany);
		}
	}

	return "Company book loaded!";
}

string PhoneBook::associatePersonWithCompany(int contactID, int companyID)
{
	
		string result;
		Contact & curContact = getContactByID(contactID);
		Company & curCompany = getCompanyByID(companyID);



		curContact.companiesAssociatedWithContact.push_back(companyID);
		curCompany.associatedContacts.push_back(contactID);


		result = curContact.name + " has been assoicated to " + curCompany.companyName + "\n";
		return result;
	
}

string PhoneBook::getCompaniesAssociatedWithContact(int conID)
{
	string result;
	Contact & testContact = getContactByID(conID);
	

	vector<int>::iterator iter;

	iter = testContact.companiesAssociatedWithContact.begin();

	while (iter != testContact.companiesAssociatedWithContact.end())
	{
		Company company;
		company = getCompanyByID((*iter));
		result += company.getCompanyName() + " ";
		iter++;
	}
	if (result.empty() == 1)
	{
		result += "No companies associated with contact";

	}
	result += "\n";
	return result;
}

string PhoneBook::addRandPerson(int count)
{
	for (int i = 0; i < count; i++)
	{
		addContact(randString(8), randString(12), randString(18));
	}
	return "Random Contacts added.";

}

string PhoneBook::addRandCompanies(int count)
{
	for (int i = 0; i < count; i++)
	{
		addCompany(randString(8), randString(12), randString(18));
	}
	return "Random Companies added.";

}

string PhoneBook::getContactAssociatedWithCompany(int comID)
{
	string result;
	Company & testCompany = getCompanyByID(comID);


	vector<int>::iterator iter;

	iter = testCompany.associatedContacts.begin();

	while (iter != testCompany.associatedContacts.end())
	{
		Contact contact;
		contact = getContactByID((*iter));
		result += contact.name;
		iter++;
	}
	if (result.empty() == 1)
	{
		result += "No contacts associated with company";

	}
	result += "\n";
	return result;
}



Company & PhoneBook::getCompanyByID(int key)
{
	vector<Company>::iterator iter;

	for (iter = vCompany.begin(); iter != vCompany.end(); iter++)
	{
		if ((*iter).companyID == key)
		{
			return (*iter);
		}
	}
	throw (string) "Company ID " + intToString(key) + " does not currently exist";
}

