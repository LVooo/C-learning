#pragma once
#include "People.h"
#include <vector>
#include "students.h"
#include "teacher.h"
#include "computerRoom.h"

class Admin : public People
{
public:
	Admin(string name, string password);

	virtual void showMenu();

	void addAccount();

	void searchAccount();

	void searchComputer();

	void clearAllBooks();

	// ��ȡѧ������ʦ������
	void initVector();

	// ȥ��
	bool checkRepeat(int id, int type);

public:
	// ���ѧ������ʦ������
	vector<Students> vStu;

	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;
};