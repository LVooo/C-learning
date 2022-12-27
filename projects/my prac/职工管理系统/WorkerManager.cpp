#include "WorkerManager.h"
#include "Worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager()
{
	// �ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->empNum = 0;
		this->empArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	// �ļ����� ��������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->empNum = 0;
		this->empArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	// ���ļ����ڲ��Ҽ�¼������  
	int num = this->getEmpNum();
	this->empNum = num;

	this->empArray = new Worker * [this->empNum];
	this->initEmp();
}

WorkerManager::~WorkerManager()
{
	if (this->empArray != NULL)
	{
		delete[] this->empArray;
	}
}

void WorkerManager::showMenu()
{
	cout << "***************************************************************" << endl;
	cout << "************       ��ӭʹ��С��ְ������ϵͳ       *************" << endl;
	cout << "*******************     0.�˳�����ϵͳ     ********************" << endl;
	cout << "*******************     1.����ְ����Ϣ     ********************" << endl;
	cout << "*******************     2.��ʾְ����Ϣ     ********************" << endl;
	cout << "*******************     3.ɾ����ְְ��     ********************" << endl;
	cout << "*******************     4.�޸�ְ����Ϣ     ********************" << endl;
	cout << "*******************     5.����ְ����Ϣ     ********************" << endl;
	cout << "*******************     6.���ձ������     ********************" << endl;
	cout << "*******************     7.��������ĵ�     ********************" << endl;
	cout << "***************************************************************" << endl;
	cout << endl;
}

void WorkerManager::exitMenu()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0); // �˳�
}

void WorkerManager::Add_Emp()
{
	int addNum;

	cout << "�������������Ա����������" ;
	cin >> addNum;
	if (addNum > 0)
	{
		// ���ȿ����¿ռ�
		int newSize = this->empNum + addNum;
		Worker** newSpace = new Worker * [newSize];

		// ��ԭ�ռ����ݷŵ��¿ռ�
		if (this->empArray != NULL)
		{
			for (int i = 0; i < empNum; i++)
			{
				newSpace[i] = empArray[i];
			}
		}

		// ����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int did;

			cout << "�������" << i + 1 << "��ְ����ţ�";

			while (true)
			{
				cin >> id;
				if (isExist(id) != -1)
				{
					cout << "�ñ���Ѵ��ڣ����������룺";
				}
				else
				{
					break;
				}
			}

			cout << "�������" << i + 1 << "��ְ��������";
			cin >> name;

			cout << "��ѡ��ְ���ĸ�λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cout << "����ѡ���ǣ�";
			cin >> did;

			Worker* worker = NULL;
			switch (did)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "��Ч���룬���������룺";
			}

			newSpace[this->empNum + i] = worker;
		}

		// �ͷ�ԭ�пռ� 
		delete []this->empArray;

		// �����¿ռ�ָ��
		this->empArray = newSpace;

		// ���¸���
		this->empNum = newSize;

		// �����ļ���Ϊ��
		this->fileIsEmpty = false;

		// ���浽�ļ�
		this->save();

		cout << "��ӳɹ���" << endl;
	}
	else
	{
		cout << "��Ч����" << endl;
	}

	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->empNum; i++)
	{
		ofs << this->empArray[i]->id << " "
			<< this->empArray[i]->name << " "
			<< this->empArray[i]->dep_id << endl;
	}

	ofs.close();
}

int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int num = 0;

	while  (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}

	return num;
}

void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* wk = NULL;

		if (did == 1)
		{
			wk = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			wk = new Manager(id, name, did);
		}
		else
		{
			wk = new Boss(id, name, did);
		}
		this->empArray[index] = wk;
		index++;
	}

	ifs.close();
}

void WorkerManager::showEmp()
{
	if (fileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < empNum; i++)
		{
			this->empArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

int WorkerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < empNum; i++)
	{
		if (this->empArray[i]->id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::deleteEmp()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "����������ɾ����ְ����ţ�";
		int id;
		cin >> id;

		int exist = isExist(id);

		if (exist != -1)
		{
			for (int i = exist; i < empNum - 1; i++)
			{
				this->empArray[i] = this->empArray[i + 1];
			}
			empNum--;

			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "�Ҳ����ó�Ա" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::modifyEmp()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		int id;
		cout << "����������Ҫ�޸ĵ�Ա����ţ�";
		cin >> id;

		int res = this->isExist(id);
		if (res != -1)
		{
			delete this->empArray[res];

			int newId = 0;
			string newName = "";
			int newDid = 0;

			cout << "���ҵ���" << id << "��Ա������������ְ���ţ�";
			cin >> newId;

			cout << "�������µ�Ա��������";
			cin >> newName;

			cout << "�������λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cout << "����ѡ���ǣ�";
			cin >> newDid;

			Worker* worker = NULL;
			switch (newDid)
			{
			case 1:
				worker = new Employee(newId, newName, 1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			case 3:
				worker = new Boss(newId, newName, 3);
				break;
			default:
				cout << "��Ч���룬���������룺";
			}

			this->empArray[res] = worker;

			cout << "�޸ĳɹ�" << endl;

			this->save();
		}
		else
		{
			cout << "�Ҳ����ó�Ա" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::searchEmp()
{
	if (fileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ���ҵķ�ʽ��" << endl;
		cout << "1. ��ְ����Ų���" << endl;
		cout << "2. ����������" << endl;

		int select;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "��������Ҫ���ҵ�Ա����ţ�";
			cin >> id;

			int res = isExist(id);
			if (res != -1)
			{
				cout << "���ҳɹ�����Ϣ���£�" << endl;
				empArray[res]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ��ó�Ա������" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < empNum; i++)
			{
				if (empArray[i]->name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��"
						<< empArray[i]->id
						<< "�ŵ���Ϣ���£�" << endl;

					flag = true;

					empArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ��ó�Ա������" << endl;
			}
		}
		else
		{
			cout << "��Ч���룬����������" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::sortEmp()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������Ҫ����ķ�ʽ��" << endl;
		cout << "1.����ְ���Ž�������" << endl;
		cout << "2.����ְ���Ž��н���" << endl;

		int select;
		cin >> select;
		for (int i = 0; i < empNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < empNum; j++)
			{
				if (select == 1)
				{
					if (empArray[minOrMax]->id > empArray[j]->id)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (empArray[minOrMax]->id < empArray[j]->id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker* tmp = this->empArray[i];
				this->empArray[i] = this->empArray[minOrMax];
				this->empArray[minOrMax] = tmp;
			}
		}

		cout << "����ɹ����������Ϊ��" << endl;
		this->save();
		this->showEmp();
	}
}

void WorkerManager::cleanFile()
{
	cout << "��ȷ��Ҫ�������������" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (empArray != NULL)
		{
			for (int i = 0; i < empNum; i++)
			{
				delete this->empArray[i];
				this->empArray[i] = NULL;
			}

			delete[] this->empArray;
			this->empArray = NULL;
			this->empNum = 0;
			this->fileIsEmpty = true;
		}

		cout << "ɾ����·��~" << endl;
	}

	system("pause");
	system("cls");
}