#pragma once
#include "Worker.h"

class Boss : public Worker
{
public:
	// ���캯��
	Boss(int id, string name, int depid);

	// �̳������Ĵ��麯��
	virtual void showInfo();

	virtual string getDep();
};