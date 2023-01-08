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
	cout << "欢迎学生代表：" << this->name << "登录！" << endl;
	cout << "\t\t -----------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    1.申请预约                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    2.查看我的预约                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    3.查看所有预约                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    4.取消预约                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    0.注销登录                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t -----------------------------------------------------\n";
	cout << "请输入您的操作：";
}

void Students::applyBook()
{
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入你要预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
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
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请输入你要预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择机房：" << endl;
	cout << "1号机房容量：" << vCom[0].maxNum << endl;
	cout << "2号机房容量：" << vCom[1].maxNum << endl;
	cout << "3号机房容量：" << vCom[2].maxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功，审核中..." << endl;

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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		if (stoi(of.orderData[i]["stuId"]) == this->id)
		{
			cout << "预约日期：周" << of.orderData[i]["date"];
			cout << " 时段：" << (of.orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "机房：" << of.orderData[i]["roomId"];
			string status = "状态：";
			if (of.orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.orderData[i]["status"] == "-1")
			{
				status += "审核未通过，预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
		else
		{
			cout << "您没有预约记录" << endl;
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.orderData[i]["date"];
		cout << " 时段：" << (of.orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << of.orderData[i]["stuId"];
		cout << " 姓名：" << of.orderData[i]["stuName"];
		cout << " 机房：" << of.orderData[i]["roomId"];
		string status = "状态：";
		if (of.orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.orderData[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.size; i++)
	{
		if (stoi(of.orderData[i]["stuId"]) == this->id)
		{
			if (of.orderData[i]["status"] == "1" || of.orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << of.orderData[i]["date"];
				cout << " 时段：" << of.orderData[i]["interval"];
				cout << " 机房：" << of.orderData[i]["roomId"];
				string status = "状态：";
				if (of.orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}

	cout << "请输入你要取消的记录，(0代表返回)" << endl;
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
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入：";
	}

	system("pause");
	system("cls");
}