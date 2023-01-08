#include "students.h"
#include "orderFile.h"
#include <algorithm>
#include <string>

Students::Students()
{

}

Students::Students(int id, string name, string password)
{
	this->id = id;
	this->name = name;
	this->password = password;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.comId && ifs >> c.maxNum)
	{
		vCom.push_back(c);
	}

	ifs.close();
}

void Students::showMenu()
{
	cout << "��ӭѧ������" << this->name << "��¼��" << endl;
	cout << "\t\t -----------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    1.����ԤԼ                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    2.�鿴�ҵ�ԤԼ                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    3.�鿴����ԤԼ                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    4.ȡ��ԤԼ                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    0.ע����¼                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t -----------------------------------------------------\n";
	cout << "���������Ĳ�����";
}

void Students::applyBook()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "��������ҪԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��������ҪԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << vCom[0].maxNum << endl;
	cout << "2�Ż���������" << vCom[1].maxNum << endl;
	cout << "3�Ż���������" << vCom[2].maxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������..." << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->id << " ";
	ofs << "stuName:" << this->name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");
}

void Students::searchMyBook()
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
		if (stoi(of.orderData[i]["stuId"]) == this->id)
		{
			cout << "ԤԼ���ڣ���" << of.orderData[i]["date"];
			cout << " ʱ�Σ�" << (of.orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "������" << of.orderData[i]["roomId"];
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
		else
		{
			cout << "��û��ԤԼ��¼" << endl;
		}
	}

	system("pause");
	system("cls");
}

void Students::searchAllBook()
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

void Students::cancelBook()
{
	OrderFile of;
	if (of.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.size; i++)
	{
		if (stoi(of.orderData[i]["stuId"]) == this->id)
		{
			if (of.orderData[i]["status"] == "1" || of.orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << of.orderData[i]["date"];
				cout << " ʱ�Σ�" << of.orderData[i]["interval"];
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
				cout << status << endl;
			}
		}
	}

	cout << "��������Ҫȡ���ļ�¼��(0������)" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "�����������������룺";
	}

	system("pause");
	system("cls");
}