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

	// 读取学生和老师的容器
	void initVector();

	// 去重
	bool checkRepeat(int id, int type);

public:
	// 存放学生和老师的容器
	vector<Students> vStu;

	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;
};