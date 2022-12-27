#include "boss.h"

Boss::Boss(int id, string name, int depid)
{
	this->id = id;
	this->name = name;
	this->dep_id = depid;
}

void Boss::showInfo()
{
	cout << "该职工的编号是：" << this->id << "\t"
		<< "该职工的姓名是：" << this->name << "\t"
		<< "该职工的岗位是：" << this->getDep() << "\t"
		<< "该职工的职责是：" << "管理公司所有事务" << endl;
}

string Boss::getDep()
{
	return "老板";
}