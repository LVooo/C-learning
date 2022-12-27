#pragma once
#include <iostream>
using namespace std;

class Worker
{
public:
	
	virtual void showInfo() = 0;

	virtual string getDepName() = 0;

	int w_id; // 职工编号
	string  w_name; // 职工姓名
	int w_depid; // 部门编号
};