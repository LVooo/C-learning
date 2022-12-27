#include <iostream>
using namespace std;
#include "WorkerManager.h"
#include "Worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


void test01()
{
	Worker* wk; 
	wk = new Employee(1, "张三", 2);
	wk->showInfo();
	delete wk;

	wk = new Manager(1, "张经理", 2);
	wk->showInfo();
	delete wk;

	wk = new Boss(1, "张老板", 2);
	wk->showInfo();
	delete wk;
}

int main()
{
	WorkerManager wm;
	int input;

	while (true)
	{
		wm.showMenu();

		cout << "请输入您的操作：" ;
		cin >> input;
		switch (input)
		{
		case 0:
			wm.exitMenu();
			break;
		case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.showEmp();
			break;
		case 3:
			wm.deleteEmp();
			break;
		case 4:
			wm.modifyEmp();
			break;
		case 5:
			wm.searchEmp();
			break;
		case 6:
			wm.sortEmp();
			break;
		case 7:
			wm.cleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}