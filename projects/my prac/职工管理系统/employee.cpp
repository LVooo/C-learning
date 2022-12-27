#include "employee.h"

Employee :: Employee(int id, string name, int depid)
{
	this->id = id;
	this->name = name;
	this->dep_id = depid;
}

void Employee::showInfo()
{
	cout << "该职工的编号是：" << this->id << "\t"
		<< "该职工的姓名是：" << this->name << "\t"
		<< "该职工的岗位是：" << this->getDep() << "\t"
		<< "该职工的职责是：" << "完成经理交给的任务" << endl;
}

string Employee::getDep()
{
	return "员工";
}