#include "Derived.h"

Derived::Derived()
{
}

Derived::~Derived()
{
	if (charArray2_)
		delete[] charArray2_;
	charArray2_ = nullptr;
}

Derived::Derived(const char * charArray1, const char * charArray2):
	Base(charArray1)
{
	charArray2_ = nullptr;

	if (!set_charArray2(charArray2))
		std::cerr << "overloaded constructor called with invalid argument\n";
}

Derived::Derived(const Derived & original) : 
	Base(original)
{
	set_charArray2(original.charArray2_);
}

Derived & Derived::operator=(const Derived & original)
{
	if (this == &original)
		return *this;
	
	Base::operator=(original);

	set_charArray2(original.charArray2_);

	return *this;
}

bool Derived::set_charArray2(const char * charArray2)
{
	if (!charArray2)
	{
		std::cerr << "set_charArray2 called with illigal argument\n";
		return false;
	}

	if (charArray2_)
	{
		delete[] charArray2_;
		charArray2_ = nullptr;
	}

	charArray2_ = new char[strlen(charArray2) + 1];

	if (!charArray2_)
		std::cerr << "memory allocation failed\n";
	else if (copy2(charArray2, charArray2_))
		return true;

	return false;
}

char * Derived::get_charArray2()
{
	return charArray2_;
}

void Derived::display()
{
	Base::display();
	std::cout << charArray2_ << charArray_;
}
