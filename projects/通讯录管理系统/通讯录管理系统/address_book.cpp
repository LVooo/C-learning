#include <iostream>
#define MAX 100
using namespace std;

struct people
{
	string pname;
	int psex;
	int page;
	int pnumber;
	string paddress;
};

struct addressBook
{
	int total_num;
	people pep[MAX];
};

// UI����
void showMsg()
{
	cout << "*******************************" << endl;
	cout << "******** 1.�����ϵ�� *********" << endl;
	cout << "******** 2.��ʾ��ϵ�� *********" << endl;
	cout << "******** 3.ɾ����ϵ�� *********" << endl;
	cout << "******** 4.������ϵ�� *********" << endl;
	cout << "******** 5.�޸���ϵ�� *********" << endl;
	cout << "******** 6.�����ϵ�� *********" << endl;
	cout << "******** 0.�˳�ͨѶ¼ *********" << endl;
	cout << "*******************************" << endl;
}

// �����ϵ��
void addContacts(addressBook* adb)
{
	int pos = adb->total_num;
	if (pos == MAX)
	{
		cout << "�����������޷��������" << endl;
		system("cls");
		return;
	}
	else
	{
		cout << "������Ҫ��ӵ���ϵ�����ƣ�" << endl;
		string name;
		cin >> name;
		adb->pep[pos].pname = name;
		cout << "������Ҫ��ӵ���ϵ���Ա�1-���ԣ�2-Ů�ԣ���" << endl;
		int sex;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				adb->pep[pos].psex = sex;
				break;
			}
			else
			{
				cout << "�Ƿ����룬����������1��2" << endl;
			}
		}
		cout << "������Ҫ��ӵ���ϵ�����䣺" << endl;
		int age;
		cin >> age;
		adb->pep[pos].page = age;
		cout << "������Ҫ��ӵ���ϵ�˵绰��" << endl;
		int number;
		cin >> number;
		adb->pep[pos].pnumber = number;
		cout << "������Ҫ��ӵ���ϵ�˼�ͥסַ��" << endl;
		string address;
		cin >> address;
		adb->pep[pos].paddress = address;

		//����ͨѶ¼����
		adb->total_num++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls"); // ��������
	}
};

// ��ʾ��ϵ��
void showContacts(addressBook* adb)
{
	int len = adb->total_num;
	if (len > 0)
	{
		cout << "ĿǰͨѶ¼�е�������Ա���£�" << endl;
		for (int i = 0; i < len; i++)
		{
			cout << "��ϵ��������" << adb->pep[i].pname << "\t�Ա�" << (adb->pep[i].psex == 1 ? "��" : "Ů") <<
				"\t���䣺" << adb->pep[i].page << "\t��ϵ�绰��" << adb->pep[i].pnumber << "\t��ͥסַ��" << adb->pep[i].paddress << endl;
		}
	}
	else
	{
		cout << "��δ����κ���" << endl;
	}

	system("pause");
	system("cls");
}

// �ж������������Ƿ����
int isExist(addressBook* adb, string name)
{
	if (adb->total_num > 0)
	{
		for (int i = 0; i < adb->total_num; i++)
		{
			if (adb->pep[i].pname == name)
			{
				return i;
			}
		}
		cout << "��ѯ��������ϵ��" << endl;
	}
	else
	{
		cout << "ͨѶ¼û�д�����" << endl;
	}

	return -1;
}

// ɾ����ϵ��
void deleteContacts(addressBook* adb)
{
	cout << "��������Ҫɾ������ϵ�����ƣ�" << endl;
	string name;
	cin >> name;

	int exist = isExist(adb, name); // ���ж��Ƿ����
	if (exist != -1)
	{
		for (int i = exist; i < adb->total_num; i++)
		{
			if ((i + 1) == MAX) // �������Խ������
			{
				break;
			}
			adb->pep[i] = adb->pep[i + 1];
		}
		adb->total_num--;
		cout << "ɾ���ɹ���" << endl;
	}

	system("pause");
	system("cls");
}

// ������ϵ��
void searchContacts(addressBook* adb)
{
	cout << "��������Ҫ���ҵ���ϵ�����ƣ�" << endl;
	string name;
	cin >> name;

	int exist = isExist(adb, name);
	if (exist != -1)
	{
		cout << "��ϵ��������" << adb->pep[exist].pname << "\t�Ա�" << (adb->pep[exist].psex == 1 ? "��" : "Ů") <<
			"\t���䣺" << adb->pep[exist].page << "\t��ϵ�绰��" << adb->pep[exist].pnumber << "\t��ͥסַ��" << adb->pep[exist].paddress << endl;
	}

	system("pause");
	system("cls");
}

// �޸���ϵ��
void modifyContacts(addressBook* adb)
{
	cout << "����������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int exist = isExist(adb, name);
	if (exist != -1)
	{
		cout << "�������޸ĺ�����ƣ�" << endl;
		string mname;
		cin >> mname;
		adb->pep[exist].pname = mname;
		cout << "�������޸ĺ���Ա�" << endl;
		int msex;
		while (true)
		{
			cin >> msex;
			if (msex == 1 || msex == 2)
			{
				adb->pep[exist].psex = msex;
				break;
			}
			else
			{
				cout << "�Ƿ����룬����������1��2��" << endl;
			}
		}
		cout << "�������޸ĺ�����䣺" << endl;
		int mage;
		cin >> mage;
		adb->pep[exist].page = mage;
		cout << "�������޸ĺ����ϵ�绰��" << endl;
		int mnumber;
		cin >> mnumber;
		adb->pep[exist].pnumber = mnumber;
		cout << "�������޸ĺ�ļ�ͥסַ��" << endl;
		string maddress;
		cin >> maddress;
		adb->pep[exist].paddress = maddress;

		cout << "�޸ĳɹ���" << endl;
		system("pause");
		system("cls");
	}

}

// ɾ����·
void clearContacts(addressBook* adb)
{
	cout << "ȷ��Ҫɾ������������ 1����ȷ��  2����ȡ��" << endl;
	int select;
	while (true)
	{
		cin >> select;
		if (select == 1 || select == 2)
		{
			if (select == 1)
			{
				adb->total_num = 0;
				cout << "ɾ����·��" << endl;
				break;
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "�Ƿ����룬����������1��2��" << endl;
		}
	}

	system("pause");
	system("cls");
}

// �������
int main()
{
	addressBook adb;
	adb.total_num = 0;

	while (true)
	{
		// ��ʼ����
		showMsg();

		int input;
		cout << "��ѡ����Ҫִ�е�ѡ�";
		cin >> input;

		// �ж�����
		switch (input)
		{
		case 1:
			addContacts(&adb);
			break;
		case (2):
			showContacts(&adb);
			break;
		case (3):
			deleteContacts(&adb);
			break;
		case(4):
			searchContacts(&adb);
			break;
		case(5):
			modifyContacts(&adb);
			break;
		case(6):
			clearContacts(&adb);
			break;
		case(0):
			cout << "���˳�����ӭ�´�����" << endl;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}