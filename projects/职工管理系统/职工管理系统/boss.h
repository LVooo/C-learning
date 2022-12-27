#pragma once
#include "worker.h"

class Boss : public Worker
{
public:

	Boss(int id, string name, int  dId);

	virtual void showInfo();

	virtual string getDepName();
};