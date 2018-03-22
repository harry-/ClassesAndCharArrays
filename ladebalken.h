#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// Name space resolutions
using std::cout;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void ladebalken(const string&, unsigned int);

void ladebalken(const string& message, unsigned int millis_per_char)
{
	for (const char c : message)
	{
		cout << c << flush;

		sleep_for(milliseconds(millis_per_char));
	}
}