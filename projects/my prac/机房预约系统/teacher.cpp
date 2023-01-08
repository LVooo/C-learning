#include "teacher.h"
#include "orderFile.h"
#include <vector>

Teacher::Teacher()
{

}

Teacher::Teacher(int id, string name, string password)
{
	this->id = id;
	this->name = name;
	this->password = password;
}

void Teacher::showMenu()
{
	cout << "��ӭ��ʦ��" << this->name << "��¼��" << endl;
	cout << "\t\t -----------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    1.�鿴����ԤԼ                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    2.���ԤԼ                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    0.ע����¼                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t -----------------------------------------------------\n";
	cout << "���������Ĳ�����";
}

void Teacher::searchAllBook()
{
	OrderFile of;
	if (of.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.orderData[i]["date"];
		cout << " ʱ�Σ�" << (of.orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << of.orderData[i]["stuId"];
		cout << " ������" << of.orderData[i]["stuName"];
		cout << " ������" << of.orderData[i]["roomId"];
		string status = "״̬��";
		if (of.orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

void Teacher::checkBook()
{
	OrderFile of;
	if (of.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.orderData[i]["date"];
		cout << " ʱ�Σ�" << (of.orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << of.orderData[i]["stuId"];
		cout << " ������" << of.orderData[i]["stuName"];
		cout << " ������" << of.orderData[i]["roomId"];
		string status = "״̬��";
		if (of.orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}

	int select = 0;
	int choice = 0;
	cout << "��������Ҫ��˵�ԤԼ������(0������)" << endl;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= of.size)
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "����������ѡ��" << endl;
				cout << "1����׼" << endl;
				cout << "2���ܾ�" << endl;
				cin >> choice;

				if (choice == 1)
				{
					of.orderData[select - 1]["status"] = "2";
				}
				else
				{
					of.orderData[select - 1]["status"] = "-1";
				}
				of.updateOrder();
				cout << "�����ɣ�" << endl;
				break;
			}
		}
		cout << "�����������������룺";
	}


	system("pause");
	system("cls");
}