#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->w_id = id;
	this->w_name = name;
	this->w_depid = dId;
}

void Manager::showInfo()
{
	cout << "职工编号为：" << this->w_id
		<< " \t职工姓名：" << this->w_name
		<< " \t岗位：" << this->getDepName()
		<< "\t岗位职责：完成老板交给的任务，并将任务分配给员工" << endl;
}

string Manager::getDepName()
{
	return string("经理");
}