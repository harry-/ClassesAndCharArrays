#pragma once
#include <iostream>
#include "copy.h"
class Base	
{
protected:
	char * charArray_{ nullptr };
public:
	Base();
	virtual ~Base();
	virtual Base* clone() const = 0;
	Base(const char * charArray);
	Base(const Base & original);
	Base & operator=(const Base & original);
	bool set_charArray(const char * charArray);
	char * get_charArray();
	virtual void display() = 0;
	Base & operator=(const Base && original) = delete; // no overloaded move operator
	Base(const Base && original) = delete; // no move constructor
};

