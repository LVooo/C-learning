#include "boss.h"

Boss::Boss(int id, string name, int depid)
{
	this->id = id;
	this->name = name;
	this->dep_id = depid;
}

void Boss::showInfo()
{
	cout << "��ְ���ı���ǣ�" << this->id << "\t"
		<< "��ְ���������ǣ�" << this->name << "\t"
		<< "��ְ���ĸ�λ�ǣ�" << this->getDep() << "\t"
		<< "��ְ����ְ���ǣ�" << "����˾��������" << endl;
}

string Boss::getDep()
{
	return "�ϰ�";
}