#pragma once
#include "Worker.h"

class Employee : public Worker
{
public:
	// ���캯��
	Employee(int id, string name, int depid);

	// �̳������Ĵ��麯��
	virtual void showInfo();

	virtual string getDep();
};