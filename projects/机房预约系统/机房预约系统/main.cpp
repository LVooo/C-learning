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

		// ������ָ�� ǿתΪ����ָ�룬���ܵ��������������ӿ�
		Admin* ad = (Admin*)admin;

		int select = 0;
		cin >> select;
		
		switch (select)
		{
		case 1:
			cout << "����˺�" << endl;
			ad->addAccount();
			break;
		case 2:
			cout << "�鿴�˺�" << endl;
			ad->searchAccount();
			break;
		case 3:
			cout << "�鿴����" << endl;
			ad->searchComputer();
			break;
		case 4:
			cout << "���ԤԼ" << endl;
			ad->clearAllBooks();
			break;
		case 0:
			delete admin;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "�������" << endl;
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
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "�������" << endl;
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
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "�������" << endl;
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
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id;
	string name;
	string password;

	if (type == 1)
	{
		cout << "���������ѧ�ţ�";
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ���ţ�";
		cin >> id;
	}

	cout << "���������������";
	cin >> name;
	cout << "������������룺";
	cin >> password;

	if (type == 1)
	{
		// ѧ����½��֤
		int fid;
		string fname;
		string fpassword;

		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (id == fid && name == fname && password == fpassword)
			{
				cout << "ѧ����֤��½�ɹ���" << endl;
				system("cls");

				person = new Students(id, name, password);
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		// ��ʦ��¼��֤
		int fid;
		string fname;
		string fpassword;

		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (id == fid && name == fname && password == fpassword)
			{
				cout << "��ʦ��֤��½�ɹ���" << endl;
				system("cls");

				person = new Teacher(id, name, password);
				teacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3)
	{
		// ����Ա��½��֤
		string fname;
		string fpassword;

		while (ifs >> fname && ifs >> fpassword)
		{
			if (name == fname && password == fpassword)
			{
				cout << "����Ա��֤��½�ɹ���" << endl;
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
		cout << "\t========================    ��ӭ������������    ========================" << endl;
		cout << endl << "������������ݣ�" << endl;
		cout << "\t\t -----------------------------------------------------\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                    1.ѧ������                       |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                    2.��    ʦ                       |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                    3.�� �� Ա                       |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t|                    0.��    ��                       |\n";
		cout << "\t\t|                                                     |\n";
		cout << "\t\t -----------------------------------------------------\n";
		cout << "����������ѡ��";

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
			cout << "��ӭ��һ��ʹ��" << endl;
			return 0;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	system("cls");
	return 0;
}