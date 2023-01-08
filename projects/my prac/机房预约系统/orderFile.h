#pragma once
#include <iostream>
using namespace std;
#include <map>
#include <fstream>
#include "globalFile.h"

class OrderFile
{
public:
	OrderFile();

	void updateOrder();

public:
	int size;
	map<int, map<string, string>> orderData;
};