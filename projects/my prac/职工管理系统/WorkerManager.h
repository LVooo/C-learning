#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "Worker.h"

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	// ���캯��
	WorkerManager();

	// ��ʾ�˵�
	void showMenu();

	// �˳�ϵͳ
	void exitMenu();

	// ���Ա��
	void Add_Emp();

	// ���浽�ļ�
	void save();

	// ͳ���ļ�������
	int getEmpNum();

	// ��ʼ��Ա��
	void initEmp();

	// ��ʾԱ��
	void showEmp();

	// �ж�Ա���Ƿ����
	int isExist(int id);

	// ɾ��Ա��
	void deleteEmp();

	// �޸�Ա��
	void modifyEmp();

	// ����Ա��
	void searchEmp();

	// ����Ա��
	void sortEmp();

	// ���
	void cleanFile();

	// ��������
	~WorkerManager();

public:
	int empNum;
	Worker** empArray;
	bool fileIsEmpty;
};