#include "manager.h"

Manager::Manager(int id, string name, int depid)
{
	this->id = id;
	this->name = name;
	this->dep_id = depid;
}

void Manager::showInfo()
{
	cout << "��ְ���ı���ǣ�" << this->id << "\t"
		<< "��ְ���������ǣ�" << this->name << "\t"
		<< "��ְ���ĸ�λ�ǣ�" << this->getDep() << "\t"
		<< "��ְ����ְ���ǣ�" << "����˾����������" << endl;
}

string Manager::getDep()
{
	return "����";
}