#include "employee.h"

Employee::Employee(int id, string name, int dId)
{
	this->w_id = id;
	this->w_name = name;
	this->w_depid = dId;
}

void Employee::showInfo()
{
	cout << "职工编号为：" << this->w_id
		<< " \t职工姓名：" << this->w_name
		<< " \t岗位：" << this->getDepName()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDepName()
{
	return string("员工");
}