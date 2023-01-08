#include <iostream>
#include "People.h"
#include "students.h"
#include "teacher.h"
#include "admin.h"
#include "globalFile.h"
#include <fstream>
using namespace std;

void adminMenu(People* &admin)
{
	while (true)
	{
		admin->showMenu();

		// 将父类指针 强转为子类指针，才能调用子类里其他接口
		Admin* ad = (Admin*)admin;

		int select = 0;
		cin >> select;
		
		switch (select)
		{
		case 1:
			cout << "添加账号" << endl;
			ad->addAccount();
			break;
		case 2:
			cout << "查看账号" << endl;
			ad->searchAccount();
			break;
		case 3:
			cout << "查看机房" << endl;
			ad->searchComputer();
			break;
		case 4:
			cout << "清空预约" << endl;
			ad->clearAllBooks();
			break;
		case 0:
			delete admin;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void studentMenu(People*& student)
{
	while (true)
	{
		student->showMenu();

		Students* stu = (Students*)student;

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1:
			stu->applyBook();
			break;
		case 2:
			stu->searchMyBook();
			break;
		case 3:
			stu->searchAllBook();
			break;
		case 4:
			stu->cancelBook();
			break;
		case 0:
			delete stu;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void teacherMenu(People*& teacher)
{
	while (true)
	{
		teacher->showMenu();

		Teacher* t = (Teacher*) teacher;

		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1:
			t->searchAllBook();
			break;
		case 2:
			t->checkBook();
			break;
		case 0:
			delete t;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void LoginIn(string fileName, int type)
{
	People* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id;
	string name;
	string password;

	if (type == 1)
	{
		cout << "请输入你的学号：";
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号：";
		cin >> id;
	}

	cout << "请输入你的姓名：";
	cin >> name;
	cout << "请输入你的密码：";
	cin >> password;

	if (type == 1)
	{
		// 学生登陆验证
		int fid;
		string fname;
		string fpassword;

		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (id == fid && name == fname && password == fpassword)
			{
				cout << "学生验证登陆成功！" << endl;
				system("cls");

				person = new Students(id, name, password);
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		// 教师登录验证
		int fid;
		string fname;
		string fpassword;

		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (id == fid && name == fname && password == fpassword)
			{
				cout << "教师验证登陆成功！" << endl;
				system("cls");

				person = new Teacher(id, name, password);
				teacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3)
	{
		// 管理员登陆验证
		string fname;
		string fpassword;

		while (ifs >> fname && ifs >> fpassword)
		{
			if (name == fname && password == fpassword)
			{
				cout << "管理员验证登陆成功！" << endl;
				system("cls");

				person = new Admin(name, password);
				adminMenu(person);

				return;
			}
		}
	}

	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;

	while (true)
	{
		cout << "\t========================    欢迎来到德莱联盟    ========================" << endl;
		cout << endl << "请输入您的身份：" << endl;
		cout << "\t\t -----------------------------------------------------\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                    1.学生代表                       |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                    2.老    师                       |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                    3.管 理 员                       |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                    0.退    出                       |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t -----------------------------------------------------\n";
		cout << "请输入您的选择：";

		cin >> select;
		cout << endl;

		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, select);
			break;
		case 2:
			LoginIn(TEACHER_FILE, select);
			break;
		case 3:
			LoginIn(ADMIN_FILE, select);
			break;
		case 0:
			cout << "欢迎下一次使用" << endl;
			return 0;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	system("cls");
	return 0;
}