#include <iostream>
#include "Derived.h"
#include <fstream>
#include <string>
#include "ClearScreen.h"
#include "ladebalken.h"

void clearCin();

int main()
{
	// log to file


 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  // you can loop k higher to see more color choices
  //for(int k = 1; k < 1000; k++)
  //{
  //  // pick the colorattribute k you want
  //  SetConsoleTextAttribute(hConsole, k);
  //  std::cout << k << " I want to be nice today!" << std::endl;
  //}
 SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
SetConsoleTextAttribute(hConsole, 14);
std::string s1;
 for(int i=0; i < 20; i++)
 s1 += (char)178;
 

 while (1)
 {
	 clear();
std::cout << "preparing to move window";
ladebalken(s1, 100);
 
 HWND console = GetConsoleWindow();
  RECT r;
  GetWindowRect(console, &r); //stores the console's current dimensions

  //MoveWindow(window_handle, x, y, width, height, redraw_window);
  MoveWindow(console, 100, 200, 800, 600, TRUE);
  clear();
  std::cout << "preparing to move window";
 ladebalken(s1, 200);


  //for (int j = 0; j < 100; ++j)
  //  {
  //    for (int i = 0x41; i < 0x5B; ++i)
  //      cout << (char)i;
  //  }
  std::cout << std::endl;
  Sleep(1000);
  MoveWindow(console, -1000, r.top, 800, 600, TRUE);

}

 HWND console = GetConsoleWindow();
  RECT r;
  GetWindowRect(console, &r); //stores the console's current dimensions

  //MoveWindow(window_handle, x, y, width, height, redraw_window);
  MoveWindow(console, 100, 200, 800, 600, TRUE);


 ladebalken(s1, 200);


  //for (int j = 0; j < 100; ++j)
  //  {
  //    for (int i = 0x41; i < 0x5B; ++i)
  //      cout << (char)i;
  //  }
  std::cout << std::endl;
  Sleep(1000);
  MoveWindow(console, -1000, r.top, 800, 600, TRUE);

	std::ofstream out("logfile.txt");
	std::clog.rdbuf(out.rdbuf());
	std::clog << "start logging" << '\n';
	
	Base* base[10] = {};
	Derived* derived{};
	Derived derived2{};
	Derived * derived3 = new Derived[10];
	delete[]derived3;

	base[0] = new Derived{"aaa", "bbbb"};
	//base[1] = new Derived{ "cccc", "ddddd" };
	//delete base[0];

	Derived * derived4 = new Derived[10];
	delete[]derived4;

	//base[1] = base[0];
	base[2] = base[0]->clone();

	for (auto i = 0; i < 10; i++)
	{
		if (base[i])
		{
			base[i]->display();
			delete base[i];
		}
	}
	Base * items[10] = {NULL};
	Base * itemsChosen[10] = {NULL};

	items[0] = new Derived("Name", "Description");
	items[1] = new Derived("Another Name", "Another Description");

	int input{-1};
	unsigned short counterChosenItems{ 0 };

	while (counterChosenItems<10)
	{
		clear();
		if (counterChosenItems)
		{
			std::cout << "Bisherige Auswahl:\n";
			for (auto i = 0; i < counterChosenItems; i++)
			{
				itemsChosen[i]->display();
				std::cout << '\n';
			}
		}
		std::cout << '\n';
		for (int i = 0; i < 10; i++)
		{
			if (items[i])
			{
				std::cout << i + 1 << ' ';
				items[i]->display();
				std::cout << '\n';
			}
		}
		std::cout << "\nDruecken Sie 0 um die Auswahl zu beenden\n\n";
		std::cout << "Auswahl: ";
		std::cin >> input;

		if (!input)
			break;

		if (items[input-1]&&input<10)
		{
			itemsChosen[counterChosenItems] = items[input-1];
			counterChosenItems++;
		}
	
	}
	for (int i = 0; i < 10; i++)
	{
		if (items[i])
		{
			delete items[i];
		}
	}
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //checks for memoryleaks

	/*clearCin();*/
	std::cin.get();
    return 0;
}


void clearCin()
{
	std::cin.clear();
	const std::int32_t cIntMax = std::numeric_limits<std::int32_t>::max();
	std::cin.ignore(cIntMax, '\n');
}