#include "boss.h"

Boss::Boss(int id, string name, int  dId)
{
	this->w_id = id;
	this->w_name = name;
	this->w_depid = dId;
}

void Boss::showInfo()
{
	cout << "职工编号为：" << this->w_id
		<< " \t职工姓名：" << this->w_name
		<< " \t岗位：" << this->getDepName()
		<< "\t岗位职责：公司都是爷的" << endl;
}

string Boss::getDepName()
{
	return string("老总");
}