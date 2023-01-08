#pragma once
#include "People.h"
#include "computerRoom.h"
#include <vector>
#include <fstream>

class Students : public People
{
public:
	Students();

	Students(int id, string name, string password);

	virtual void showMenu();

	void applyBook();

	void searchMyBook();

	void searchAllBook();

	void cancelBook();

public:
	int id;
	vector<ComputerRoom> vCom;
};