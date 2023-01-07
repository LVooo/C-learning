#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// 文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl; // 测试输出
		this->m_EmpNum = 0; // 初始化人数
		this->m_EmpArray = NULL; // 初始化数组
		this->m_FileIsEmpty = true; // 初始化文件为空标志
		ifs.close(); // 关闭文件
		return;
	}

	// 文件存在 并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空！" << endl;
		this->m_EmpNum = 0; // 初始化人数
		this->m_EmpArray = NULL; // 初始化数组
		this->m_FileIsEmpty = true; // 初始化文件为空标志
		ifs.close(); // 关闭文件
		return;
	}

	int num = this->get_EmpNum();
	this->m_EmpNum = num;
	// 根据员工数创建数组
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// 初始化职工
	init_Emp();
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
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
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "请输入增加职工的数量：" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		// 计算新空间大小
		int newSize = this->m_EmpNum + addNum;

		// 开辟新空间
		Worker** newSpace = new Worker * [newSize];

		// 将原空间下内容存放到新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// 输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1. 普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
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
				cout << "输入有误，重新输入："; // 此处有bug，应用while循环判断
			}

			newSpace[this->m_EmpNum + i] = worker;
		}

		// 释放原有空间
		delete[] this->m_EmpArray;

		// 更改新空间的指向
		this->m_EmpArray = newSpace;

		// 更新新的个数
		this->m_EmpNum = newSize;

		// 更新职工不为空标志
		this->m_FileIsEmpty = false;

		// 提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;

		// 保存数据到文件中
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}

	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->w_id << " "
			<< this->m_EmpArray[i]->w_name << " "
			<< this->m_EmpArray[i]->w_depid << endl;
	}

	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		// 记录人数
		num++;
	}
	ifs.close();

	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		// 根据不同部门Id创建不同对象
		if (dId == 1) // 1.普通员工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) // 2.经理
		{
			worker = new Manager(id, name, dId);
		}
		else // 总裁
		{
			worker = new Boss(id, name, dId);
		}
		// 存放在数组中
		this->m_EmpArray[index++] = worker;
	}
}

// 显示职工
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			// 利用多态调用接口
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

// 判断职工是否存在
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->w_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

// 删除职工实现
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		// 按职工编号删除
		cout << "输入你想要删除的职工号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save(); // 删除后记得同步到文件中
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}

	system("pause");
	system("cls");
}

// 修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int res = this->IsExist(id);
		if (res != -1)
		{
			// 查找到编号的职工
			delete this->m_EmpArray[res];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newId;

			cout << "请输入新姓名：" << endl;
			cin >> newName;

			cout << "请输入岗位：" << endl;
			cout << "1. 普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			// 更改数据 到数组中
			this->m_EmpArray[res] = worker;
			
			cout << "修改成功！" << endl;

			// 保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}

	system("pause");
	system("cls");
}

// 查找职工实现
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1. 按职工编号查找" << endl;
		cout << "2. 按姓名查找" << endl;

		int select = 0;
		cin >> select;
		
		if (select == 1) // 按职工编号查找
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int res = IsExist(id);
			if (res != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[res]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2) // 按姓名查找
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->w_name == name)
				{
					cout << "查找成功，职工编号为："
						<< m_EmpArray[i]->w_id
						<< "号的信息如下：" << endl;

					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}

	system("pause");
	system("cls");
}

// 排序职工实现
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入排序的方式：" << endl;
		cout << "1. 按职工号进行升序排序" << endl;
		cout << "2. 按职工号进行降序排序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			// 使用选择排序
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1) // 升序
				{
					if (m_EmpArray[minOrMax]->w_id > m_EmpArray[j]->w_id)
					{
						minOrMax = j;
					}
				}
				else // 降序
				{
					if (m_EmpArray[minOrMax]->w_id < m_EmpArray[j]->w_id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}

		cout << "排序完成，排序后结果为：" << endl;
		this->save();
		this->Show_Emp();
	}
}

// 清空文件
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1. 确认" << endl;
	cout << "2. 返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		// 先进行文件操作：
		// 打开模式 ios::trunc 如果存在 删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "删库跑路啦~" << endl;
	}

	system("pause");
	system("cls");
}