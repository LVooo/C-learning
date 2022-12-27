#include "WorkerManager.h"
#include "Worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager()
{
	// 文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->empNum = 0;
		this->empArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	// 文件存在 但是数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->empNum = 0;
		this->empArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	// 当文件存在并且记录了数据  
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
	cout << "************       欢迎使用小李职工管理系统       *************" << endl;
	cout << "*******************     0.退出管理系统     ********************" << endl;
	cout << "*******************     1.增加职工信息     ********************" << endl;
	cout << "*******************     2.显示职工信息     ********************" << endl;
	cout << "*******************     3.删除离职职工     ********************" << endl;
	cout << "*******************     4.修改职工信息     ********************" << endl;
	cout << "*******************     5.查找职工信息     ********************" << endl;
	cout << "*******************     6.按照编号排序     ********************" << endl;
	cout << "*******************     7.清空所有文档     ********************" << endl;
	cout << "***************************************************************" << endl;
	cout << endl;
}

void WorkerManager::exitMenu()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0); // 退出
}

void WorkerManager::Add_Emp()
{
	int addNum;

	cout << "请输入你想添加员工的数量：" ;
	cin >> addNum;
	if (addNum > 0)
	{
		// 首先开辟新空间
		int newSize = this->empNum + addNum;
		Worker** newSpace = new Worker * [newSize];

		// 将原空间内容放到新空间
		if (this->empArray != NULL)
		{
			for (int i = 0; i < empNum; i++)
			{
				newSpace[i] = empArray[i];
			}
		}

		// 输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int did;

			cout << "请输入第" << i + 1 << "个职工编号：";

			while (true)
			{
				cin >> id;
				if (isExist(id) != -1)
				{
					cout << "该编号已存在，请重新输入：";
				}
				else
				{
					break;
				}
			}

			cout << "请输入第" << i + 1 << "个职工姓名：";
			cin >> name;

			cout << "请选择职工的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cout << "您的选择是：";
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
				cout << "无效输入，请重新输入：";
			}

			newSpace[this->empNum + i] = worker;
		}

		// 释放原有空间 
		delete []this->empArray;

		// 更改新空间指向
		this->empArray = newSpace;

		// 更新个数
		this->empNum = newSize;

		// 更新文件不为空
		this->fileIsEmpty = false;

		// 保存到文件
		this->save();

		cout << "添加成功！" << endl;
	}
	else
	{
		cout << "无效输入" << endl;
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
		cout << "文件不存在或者文件为空" << endl;
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
		cout << "文件不存在或者文件为空" << endl;
	}
	else
	{
		cout << "请输入你想删除的职工编号：";
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
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "找不到该成员" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::modifyEmp()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		int id;
		cout << "请输入你想要修改的员工编号：";
		cin >> id;

		int res = this->isExist(id);
		if (res != -1)
		{
			delete this->empArray[res];

			int newId = 0;
			string newName = "";
			int newDid = 0;

			cout << "查找到：" << id << "号员工，请输入新职工号：";
			cin >> newId;

			cout << "请输入新的员工姓名：";
			cin >> newName;

			cout << "请输入岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cout << "您的选择是：";
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
				cout << "无效输入，请重新输入：";
			}

			this->empArray[res] = worker;

			cout << "修改成功" << endl;

			this->save();
		}
		else
		{
			cout << "找不到该成员" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::searchEmp()
{
	if (fileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		cout << "请输入你要查找的方式：" << endl;
		cout << "1. 按职工编号查找" << endl;
		cout << "2. 按姓名查找" << endl;

		int select;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "请输入你要查找的员工编号：";
			cin >> id;

			int res = isExist(id);
			if (res != -1)
			{
				cout << "查找成功，信息如下：" << endl;
				empArray[res]->showInfo();
			}
			else
			{
				cout << "查找失败，该成员不存在" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < empNum; i++)
			{
				if (empArray[i]->name == name)
				{
					cout << "查找成功，职工编号为："
						<< empArray[i]->id
						<< "号的信息如下：" << endl;

					flag = true;

					empArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败，该成员不存在" << endl;
			}
		}
		else
		{
			cout << "无效输入，请重新输入" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::sortEmp()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入你要排序的方式：" << endl;
		cout << "1.按照职工号进行升序" << endl;
		cout << "2.按照职工号进行降序" << endl;

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

		cout << "排序成功，排序后结果为：" << endl;
		this->save();
		this->showEmp();
	}
}

void WorkerManager::cleanFile()
{
	cout << "你确定要清空所有数据吗：" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;

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

		cout << "删库跑路啦~" << endl;
	}

	system("pause");
	system("cls");
}