#include <iostream>
#include "Derived.h"

int main()
{
	Base* base[10] = {};
	Derived* derived{};
	Derived derived2{};
	Derived * derived3 = new Derived[10];
	delete[]derived3;

	base[0] = new Derived{"aaa", "bbbb"};
	//base[1] = new Derived{ "cccc", "ddddd" };
	//delete base[0];

	for (auto i = 0; i < 10; i++)
	{
		if (base[i])
		{
			base[i]->display();
			delete base[i];
		}
	}

	
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //checks for memoryleaks

    return 0;
}

