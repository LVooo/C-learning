#pragma once
#include <iostream>
using namespace std;

class Worker
{
public:
	
	virtual void showInfo() = 0;

	virtual string getDepName() = 0;

	int w_id; // ְ�����
	string  w_name; // ְ������
	int w_depid; // ���ű��
};