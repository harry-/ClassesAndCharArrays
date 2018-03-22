#pragma once
#include "Base.h"
class Derived :
	public Base
{
protected:
	char * charArray2_{ nullptr };
public:
	Derived();
	~Derived();
	virtual Base* clone() const { return new Derived(*this); }
	Derived(const char * charArray1, const char * charArray2);
	Derived(const Derived & original);
	Derived & operator=(const Derived & original);
	bool set_charArray2(const char * charArray2);
	char * get_charArray2();
	void display();
	Derived & operator=(const Derived && original) = delete; // no overloaded move operator
	Derived(const Derived && original) = delete; // no move constructor
};


