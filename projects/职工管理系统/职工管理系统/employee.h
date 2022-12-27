#pragma once
#include "worker.h"

// 员工类
class Employee : public Worker
{
public:

	// 构造函数
	Employee(int id, string name, int dId);

	// 显示个人信息
	virtual void showInfo();

	// 获取部门名称
	virtual string getDepName();
};