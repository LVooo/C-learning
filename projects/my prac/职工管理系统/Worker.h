#pragma once
#include <iostream>
using namespace std;

class Worker
{
public:
	virtual void showInfo() = 0; // ���麯��
	virtual string getDep() = 0; 

	int id;
	string name;
	int dep_id;
};