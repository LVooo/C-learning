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
	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;

	ifs.close();
}

void Admin::showMenu()
{
	cout << "��ӭ����Ա��" << this->name << "��¼��" << endl;
	cout << "\t\t -----------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    1.����˺�                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    2.�鿴�˺�                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    3.�鿴����                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    4.���ԤԼ                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    0.ע����¼                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t -----------------------------------------------------\n";
	cout << "���������Ĳ�����";
}

void Admin::addAccount()
{
	cout << "��������Ҫ������������˺ţ�" << endl;
	cout << "1.ѧ��" << endl;
	cout << "2.��ʦ" << endl;

	int select = 0;
	cin >> select;

	string fileName;
	string tip;
	string errorTip;
	ofstream ofs;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������룺";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ���ţ�";
		errorTip = "ְ�����ظ������������룺";
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
	

	cout << "������������";
	cin >> name;

	cout << "���������룺";
	cin >> password;

	ofs << id << " " << name << " " << password << endl;
	cout << "��ӳɹ���" << endl;
	this->initVector();

	system("pause");
	system("cls");
	
	ofs.close();
}

void printStudent(Students& s)
{
	cout << "ѧ�ţ�" << s.id << " ������" << s.name << " ���룺" << s.password << endl;
}

void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.id << " ������" << t.name << " ���룺" << t.password << endl;
}

void Admin::searchAccount()
{
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴���н�ʦ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ������Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "���н�ʦ����Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

void Admin::searchComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->comId << " �������������" << it->maxNum << endl;
	}
	system("pause");
	system("cls");
}

void Admin::clearAllBooks()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

void Admin::initVector()
{
	// ��ȡѧ���ļ���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	this->vStu.clear();
	this->vTea.clear();

	Students s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.password)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	// ��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);

	Teacher tea;
	while (ifs >> tea.id && ifs >> tea.name && ifs >> tea.password)
	{
		vTea.push_back(tea);
	}
	cout << "��ǰ��ʦ������Ϊ��" << vTea.size() << endl;
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