#include "Contact.h"

int Contact::lastContactIDUsed = 0;


bool compareByCat(Contact & c1, Contact & c2)
{
	return c1.catagory < c2.catagory;
}