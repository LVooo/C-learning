#include "employee.h"

Employee :: Employee(int id, string name, int depid)
{
	this->id = id;
	this->name = name;
	this->dep_id = depid;
}

void Employee::showInfo()
{
	cout << "��ְ���ı���ǣ�" << this->id << "\t"
		<< "��ְ���������ǣ�" << this->name << "\t"
		<< "��ְ���ĸ�λ�ǣ�" << this->getDep() << "\t"
		<< "��ְ����ְ���ǣ�" << "��ɾ�����������" << endl;
}

string Employee::getDep()
{
	return "Ա��";
}