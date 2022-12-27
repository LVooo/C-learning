#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "Worker.h"

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	// 构造函数
	WorkerManager();

	// 显示菜单
	void showMenu();

	// 退出系统
	void exitMenu();

	// 添加员工
	void Add_Emp();

	// 保存到文件
	void save();

	// 统计文件中人数
	int getEmpNum();

	// 初始化员工
	void initEmp();

	// 显示员工
	void showEmp();

	// 判断员工是否存在
	int isExist(int id);

	// 删除员工
	void deleteEmp();

	// 修改员工
	void modifyEmp();

	// 查找员工
	void searchEmp();

	// 排序员工
	void sortEmp();

	// 清空
	void cleanFile();

	// 析构函数
	~WorkerManager();

public:
	int empNum;
	Worker** empArray;
	bool fileIsEmpty;
};