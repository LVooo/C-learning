#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->w_id = id;
	this->w_name = name;
	this->w_depid = dId;
}

void Manager::showInfo()
{
	cout << "ְ�����Ϊ��" << this->w_id
		<< " \tְ��������" << this->w_name
		<< " \t��λ��" << this->getDepName()
		<< "\t��λְ������ϰ彻�������񣬲�����������Ա��" << endl;
}

string Manager::getDepName()
{
	return string("����");
}