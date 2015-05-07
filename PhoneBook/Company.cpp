#include "Company.h"
#include "PhoneBook.h"

int Company::lastCompanyIDUsed = 1000;

bool companyCompareByCat(Company & c1, Company & c2)
{
	return c1.companyCatagory < c2.companyCatagory;
}