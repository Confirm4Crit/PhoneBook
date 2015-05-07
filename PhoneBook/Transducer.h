#pragma once
#include <string>
#include "PhoneBook.h"

using namespace std;




class Transducer
{
public:
	string transduce(string command);
private:
	PhoneBook phonebook;

};