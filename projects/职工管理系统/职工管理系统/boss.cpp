#include "boss.h"

Boss::Boss(int id, string name, int  dId)
{
	this->w_id = id;
	this->w_name = name;
	this->w_depid = dId;
}

void Boss::showInfo()
{
	cout << "ְ�����Ϊ��" << this->w_id
		<< " \tְ��������" << this->w_name
		<< " \t��λ��" << this->getDepName()
		<< "\t��λְ�𣺹�˾����ү��" << endl;
}

string Boss::getDepName()
{
	return string("����");
}