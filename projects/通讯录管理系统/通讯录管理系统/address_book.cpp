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

// UI界面
void showMsg()
{
	cout << "*******************************" << endl;
	cout << "******** 1.添加联系人 *********" << endl;
	cout << "******** 2.显示联系人 *********" << endl;
	cout << "******** 3.删除联系人 *********" << endl;
	cout << "******** 4.查找联系人 *********" << endl;
	cout << "******** 5.修改联系人 *********" << endl;
	cout << "******** 6.清空联系人 *********" << endl;
	cout << "******** 0.退出通讯录 *********" << endl;
	cout << "*******************************" << endl;
}

// 添加联系人
void addContacts(addressBook* adb)
{
	int pos = adb->total_num;
	if (pos == MAX)
	{
		cout << "输入已满，无法继续添加" << endl;
		system("cls");
		return;
	}
	else
	{
		cout << "请输入要添加的联系人名称：" << endl;
		string name;
		cin >> name;
		adb->pep[pos].pname = name;
		cout << "请输入要添加的联系人性别（1-男性，2-女性）：" << endl;
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
				cout << "非法输入，请重新输入1或2" << endl;
			}
		}
		cout << "请输入要添加的联系人年龄：" << endl;
		int age;
		cin >> age;
		adb->pep[pos].page = age;
		cout << "请输入要添加的联系人电话：" << endl;
		int number;
		cin >> number;
		adb->pep[pos].pnumber = number;
		cout << "请输入要添加的联系人家庭住址：" << endl;
		string address;
		cin >> address;
		adb->pep[pos].paddress = address;

		//更新通讯录人数
		adb->total_num++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls"); // 清屏操作
	}
};

// 显示联系人
void showContacts(addressBook* adb)
{
	int len = adb->total_num;
	if (len > 0)
	{
		cout << "目前通讯录中的所有人员如下：" << endl;
		for (int i = 0; i < len; i++)
		{
			cout << "联系人姓名：" << adb->pep[i].pname << "\t性别：" << (adb->pep[i].psex == 1 ? "男" : "女") <<
				"\t年龄：" << adb->pep[i].page << "\t联系电话：" << adb->pep[i].pnumber << "\t家庭住址：" << adb->pep[i].paddress << endl;
		}
	}
	else
	{
		cout << "尚未添加任何人" << endl;
	}

	system("pause");
	system("cls");
}

// 判断搜索的名字是否存在
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
		cout << "查询不到此联系人" << endl;
	}
	else
	{
		cout << "通讯录没有此数据" << endl;
	}

	return -1;
}

// 删除联系人
void deleteContacts(addressBook* adb)
{
	cout << "请输入想要删除的联系人名称：" << endl;
	string name;
	cin >> name;

	int exist = isExist(adb, name); // 先判断是否存在
	if (exist != -1)
	{
		for (int i = exist; i < adb->total_num; i++)
		{
			if ((i + 1) == MAX) // 解决数组越界问题
			{
				break;
			}
			adb->pep[i] = adb->pep[i + 1];
		}
		adb->total_num--;
		cout << "删除成功！" << endl;
	}

	system("pause");
	system("cls");
}

// 查找联系人
void searchContacts(addressBook* adb)
{
	cout << "请输入想要查找的联系人名称：" << endl;
	string name;
	cin >> name;

	int exist = isExist(adb, name);
	if (exist != -1)
	{
		cout << "联系人姓名：" << adb->pep[exist].pname << "\t性别：" << (adb->pep[exist].psex == 1 ? "男" : "女") <<
			"\t年龄：" << adb->pep[exist].page << "\t联系电话：" << adb->pep[exist].pnumber << "\t家庭住址：" << adb->pep[exist].paddress << endl;
	}

	system("pause");
	system("cls");
}

// 修改联系人
void modifyContacts(addressBook* adb)
{
	cout << "请输入你想要修改的联系人：" << endl;
	string name;
	cin >> name;

	int exist = isExist(adb, name);
	if (exist != -1)
	{
		cout << "请输入修改后的名称：" << endl;
		string mname;
		cin >> mname;
		adb->pep[exist].pname = mname;
		cout << "请输入修改后的性别：" << endl;
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
				cout << "非法输入，请重新输入1或2：" << endl;
			}
		}
		cout << "请输入修改后的年龄：" << endl;
		int mage;
		cin >> mage;
		adb->pep[exist].page = mage;
		cout << "请输入修改后的联系电话：" << endl;
		int mnumber;
		cin >> mnumber;
		adb->pep[exist].pnumber = mnumber;
		cout << "请输入修改后的家庭住址：" << endl;
		string maddress;
		cin >> maddress;
		adb->pep[exist].paddress = maddress;

		cout << "修改成功！" << endl;
		system("pause");
		system("cls");
	}

}

// 删库跑路
void clearContacts(addressBook* adb)
{
	cout << "确认要删除所有数据吗？ 1——确认  2——取消" << endl;
	int select;
	while (true)
	{
		cin >> select;
		if (select == 1 || select == 2)
		{
			if (select == 1)
			{
				adb->total_num = 0;
				cout << "删库跑路啦" << endl;
				break;
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "非法输入，请重新输入1或2：" << endl;
		}
	}

	system("pause");
	system("cls");
}

// 程序入口
int main()
{
	addressBook adb;
	adb.total_num = 0;

	while (true)
	{
		// 开始界面
		showMsg();

		int input;
		cout << "请选择您要执行的选项：";
		cin >> input;

		// 判断输入
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
			cout << "已退出，欢迎下次再来" << endl;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}