#include "employee.h"

Employee::Employee(int id, string name, int dId)
{
	this->w_id = id;
	this->w_name = name;
	this->w_depid = dId;
}

void Employee::showInfo()
{
	cout << "ְ�����Ϊ��" << this->w_id
		<< " \tְ��������" << this->w_name
		<< " \t��λ��" << this->getDepName()
		<< "\t��λְ����ɾ�����������" << endl;
}

string Employee::getDepName()
{
	return string("Ա��");
}