#pragma once
#include <string>
using namespace std;

class Train
{
public: 
	Train(int number, string destination, string time);

private:
	int number;
	string destination;
	string time;

public:
	int GetNumber() { return number; }
	string GetDestination() {return destination; }
	string GetTime() { return time; }
};

