#pragma once
#include "Worker.h"

class Manager : public Worker
{
public:
	// ���캯��
	Manager(int id, string name, int depid);

	// �̳������Ĵ��麯��
	virtual void showInfo();

	virtual string getDep();
};