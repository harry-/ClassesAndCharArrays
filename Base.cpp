#include "Base.h"

Base::Base()
{
}

Base::~Base()
{
	if (charArray_)
		delete[] charArray_;
	charArray_ = nullptr;
}

Base::Base(const char * charArray)
{
	charArray_ = nullptr;
	
	if (!set_charArray(charArray))
		std::cerr << "overloaded constructor called with invalid argument\n";
}

Base::Base(const Base & original)
{
	set_charArray(original.charArray_);
}

Base & Base::operator=(const Base & original)
{
	if (this == &original)
		return *this;

	set_charArray(original.charArray_);

	return *this;
}

bool Base::set_charArray(const char * charArray)
{
	if (!charArray)
	{
		std::cerr << "set_charArray called with illegal argument\n";
		return false;
	}

	if (charArray_)
	{
		delete[] charArray_;
		charArray_ = nullptr;
	}

	charArray_ = new char[strlen(charArray) + 1];
	
	if (!charArray_)
		std::cerr << "memory allocation failed\n";
	else if(copy2(charArray, charArray_))
		return true;

	return false;
}

char * Base::get_charArray()
{
	return charArray_;
}

void Base::display()
{
	std::cout << charArray_;
}
