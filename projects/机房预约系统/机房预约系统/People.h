#pragma once
#include <iostream>
#include <fstream>
#include "globalFile.h"
using namespace std;

class People
{
public:
	virtual void showMenu() = 0;

	string name;
	string password;
};