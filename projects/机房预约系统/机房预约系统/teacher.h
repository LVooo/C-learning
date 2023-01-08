#pragma once
#include "People.h"

class Teacher : public People
{
public:
	Teacher();

	Teacher(int id, string name, string password);

	virtual void showMenu();

	void searchAllBook();

	void checkBook();

public:
	int id;
};