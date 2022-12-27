#pragma once
#include "Worker.h"

class Employee : public Worker
{
public:
	// 构造函数
	Employee(int id, string name, int depid);

	// 继承下来的纯虚函数
	virtual void showInfo();

	virtual string getDep();
};