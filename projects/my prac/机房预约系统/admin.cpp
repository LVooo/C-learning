#include "admin.h"
#include "students.h"
#include "teacher.h"
#include <algorithm>

Admin::Admin(string name, string password)
{
	this->name = name;
	this->password = password;

	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.comId && ifs >> c.maxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为：" << vCom.size() << endl;

	ifs.close();
}

void Admin::showMenu()
{
	cout << "欢迎管理员：" << this->name << "登录！" << endl;
	cout << "\t\t -----------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    1.添加账号                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    2.查看账号                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    3.查看机房                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    4.清空预约                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    0.注销登录                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t -----------------------------------------------------\n";
	cout << "请输入您的操作：";
}

void Admin::addAccount()
{
	cout << "请输入你要添加以下哪种账号：" << endl;
	cout << "1.学生" << endl;
	cout << "2.老师" << endl;

	int select = 0;
	cin >> select;

	string fileName;
	string tip;
	string errorTip;
	ofstream ofs;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入：";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工号：";
		errorTip = "职工号重复，请重新输入：";
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string password;
	cout << tip;

	while (true)
	{
		cin >> id;
		bool flag = checkRepeat(id, select);

		if (flag)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	

	cout << "请输入姓名：";
	cin >> name;

	cout << "请输入密码：";
	cin >> password;

	ofs << id << " " << name << " " << password << endl;
	cout << "添加成功！" << endl;
	this->initVector();

	system("pause");
	system("cls");
	
	ofs.close();
}

void printStudent(Students& s)
{
	cout << "学号：" << s.id << " 姓名：" << s.name << " 密码：" << s.password << endl;
}

void printTeacher(Teacher& t)
{
	cout << "职工号：" << t.id << " 姓名：" << t.name << " 密码：" << t.password << endl;
}

void Admin::searchAccount()
{
	cout << "请选择查看的内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有教师" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "所有学生的信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有教师的信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

void Admin::searchComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->comId << " 机房最大容量：" << it->maxNum << endl;
	}
	system("pause");
	system("cls");
}

void Admin::clearAllBooks()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

void Admin::initVector()
{
	// 读取学生文件信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	this->vStu.clear();
	this->vTea.clear();

	Students s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.password)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为：" << vStu.size() << endl;
	ifs.close();

	// 读取老师信息
	ifs.open(TEACHER_FILE, ios::in);

	Teacher tea;
	while (ifs >> tea.id && ifs >> tea.name && ifs >> tea.password)
	{
		vTea.push_back(tea);
	}
	cout << "当前老师的数量为：" << vTea.size() << endl;
	ifs.close();
}

bool Admin::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Students>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->id)
			{
				return true;
			}
		}
	}

	return false;
}