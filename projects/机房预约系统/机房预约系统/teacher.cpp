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
	cout << "欢迎教师：" << this->name << "登录！" << endl;
	cout << "\t\t -----------------------------------------------------\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    1.查看所有预约                   |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    2.审核预约                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t|                    0.注销登录                       |\n";
	cout << "\t\t|                                                     |\n";
	cout << "\t\t -----------------------------------------------------\n";
	cout << "请输入您的操作：";
}

void Teacher::searchAllBook()
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

void Teacher::checkBook()
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

	int select = 0;
	int choice = 0;
	cout << "请输入你要审核的预约条数，(0代表返回)" << endl;
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
				cout << "请输入您的选择：" << endl;
				cout << "1、批准" << endl;
				cout << "2、拒绝" << endl;
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
				cout << "审核完成！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入：";
	}


	system("pause");
	system("cls");
}