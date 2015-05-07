#include "Transducer.h"
#include <vector>
#include "misc.h"
using namespace std;


//ADD This is a string.

string Transducer::transduce(string command)
{
	try{
		string result;
		vector<string> token = tokenize(command);
		if ((token[0] == "HELP") || (token[0] == "H"))
		{
			result = "Commands:\n";
			result += "-------------------\n";
			result += "\tADD(A) Adds a contact noted as <name>;<number>;<catagory>\n";
			result += "\tREMOVE(R) Removes a contact as <name>\n";
			result += "\tSHOW(S) Displays your Phone Book\n";
			result += "\tSHOWCAT(SC) Displays your phone book, sorted by catagory\n";
			result += "\tSAVE(SB) Saves your Phone Book as <filename>\n";
			result += "\tLOAD(LB) Load your Phone Book named <filename>\n";
			result += "\tCOUNT(CN) Displays the number of contacts\n";
			result += "\tCLEAR(CR) Clears your contacts\n";
			result += "-------------------\n";
			result += "\tADDCOMPANY(ACOM) Adds a company as <name>;<address>;<catagory>\n";
			result += "\tREMOVECOMPANY(RCOM) Removes a company by <name>;\n";
			result += "\tSHOWCOMPANIES(SCOM) Shows companies\n";
			result += "\tSHOWCOMPANIESCAT(SCOMCAT) Sorts company list by catagory\n";
			result += "\tCLEARCOMPANIES(CRCOMP) Clears your companies\n";
			result += "\tCOMPANYCOUNT(COMPCN) Displays the number of companies\n";
			result += "-------------------\n";
			result += "\tASSOCIATE(ASS)Associates contact to a company <contact ID>;<company ID>\n";
			result += "-------------------\n";
			result += "\tADDRANDPERSON(ARP) Adds random contacts as <count>;\n";
			result += "\tADDRANDOMCOMPANIES(ARC) Adds random companies as <count>\n";
			result += "-------------------\n";
			result += "\tHELP(H)\n";
			result += "\tQUIT(Q)\n";
		}

		else if ((token[0] == "ADD") || (token[0] == "A"))
		{
			if (token.size() != 4)
			{
				throw "ERROR: Wrong Number of Parameters.";
			}
			else
			{
				result = phonebook.addContact(token[1], token[2], token[3]);
			}
		}
		else if ((token[0] == "REMOVE") || (token[0] == "R"))
		{
			if (token.size() != 2)
			{
				throw "ERROR: Wrong Number of Parameters.";
			}
			else
			{
				result = phonebook.removeContact(token[1]);
			}
		}
		else if ((token[0] == "SHOW") || (token[0] == "S"))
		{
			result = phonebook.display();
		}
		else if ((token[0] == "SHOWCAT") || (token[0] == "SC"))
		{
			result = phonebook.displayByCat();
		}
		else if ((token[0] == "SAVE") || (token[0] == "SB"))
		{
			if (token.size() != 2)
			{
				throw "ERROR: Wrong Number of Parameters.";
			}
			else
			{
				result += phonebook.saveBook(token[1]);
				result += phonebook.saveCompanies(token[1]);
			}
		}
		else if ((token[0] == "LOAD") || (token[0] == "LB"))
		{
			if (token.size() != 2)
			{
				throw "ERROR: Wrong Number of Parameters.";
			}
			else
			{
				result += phonebook.loadBook(token[1]);
				result += phonebook.loadCompanies(token[1]);
			}
		}
		else if ((token[0] == "COUNT") || (token[0] == "CN"))
		{
			result = "There is/are " + intToString(phonebook.size()) + " companies(s) in your book.";
		}
		else if ((token[0] == "CLEAR") || (token[0] == "CR"))
		{
			result = phonebook.clearContacts();
		}
		else if ((token[0] == "ADDCOMPANY") || (token[0] == "ACOM"))
		{
			if (token.size() != 4)
			{
				throw "ERROR: Wrong Number of Parameters.";
			}
			else
			{
				result = phonebook.addCompany(token[1], token[2], token[3]);
			}
		}
		else if ((token[0] == "REMOVECOMPANY") || (token[0] == "RCOM"))
		{
			if (token.size() != 2)
			{
				throw "ERROR: Wrong Number of Parameters.";
			}
			else
			{
				result = phonebook.removeCompany(token[1]);
			}
		}
		else if ((token[0] == "SHOWCOMPANIES") || (token[0] == "SCOM"))
		{
			result = phonebook.displayCompanies();
		}
		else if ((token[0] == "SHOWCOMPANIESCAT") || (token[0] == "SCOMCAT"))
		{
			result = phonebook.displayCompaniesByCat();
		}
		else if ((token[0] == "CLEARCOMPANIES") || (token[0] == "CRCOMP"))
		{
			result = phonebook.clearCompanies();
		}
		else if ((token[0] == "COMPANYCOUNT") || (token[0] == "COMPCN"))
		{
			result = "There is/are " + intToString(phonebook.companiessize()) + " company(ies) in your book.";
		}
		else if ((token[0] == "ASSOCIATE") || (token[0] == "ASS"))
		{
			if (token.size() != 3)
			{
				throw "ERROR: Wrong Number of Parameters.";
			}
			else
			{
				result = phonebook.associatePersonWithCompany(stringToInt(token[1]), stringToInt(token[2]));
			}
		}
		else if ((token[0] == "ADDRANDPERSON") || (token[0] == "ARP"))
		{
			if (token.size() != 2)
			{
				throw "ERROR: Wrong Number of Parameters.";
			}
			else
			{
				result = phonebook.addRandPerson(stringToInt(token[1]));
			}
		}
		else if ((token[0] == "ADDRANDOMCOMPANIES") || (token[0] == "ARC"))
		{
			if (token.size() != 2)
			{
				throw "ERROR: Wrong Number of Parameters.";
			}
			else
			{
				result = phonebook.addRandCompanies(stringToInt(token[1]));
			}
		}
		else if ((token[0] == "QUIT") || (token[0] == "Q"))
		{
			result = "Goodbye.";
		}
		else
		{
			throw "Unrecognized Command!!!";
		}
		return result;
	}
	catch (string es)
	{
		return es;
	}
	catch (char * es)
	{
		return es;
	}
}