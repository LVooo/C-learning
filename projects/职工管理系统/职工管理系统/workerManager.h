#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "worker.h"

#define  FILENAME "empFile.txt"

class WorkerManager
{
public:
	// ���캯��
	WorkerManager();

	// ��ʾ�˵�
	void showMenu();

	// �˳��˵�
	void exitMenu();

	// ����ְ��
	void Add_Emp();

	// �����ļ�
	void save();

	// ͳ������
	int get_EmpNum();

	// ��ʼ��Ա��
	void init_Emp();

	// ��ʾְ��
	void Show_Emp();

	// ɾ��ְ��
	void Del_Emp();

	// ����ְ������ж�ְ���Ƿ���ڣ������ڷ���ְ����������λ�ã������ڷ���-1
	int IsExist(int id);

	// �޸�ְ��
	void Mod_Emp();

	// ����ְ��
	void Find_Emp();

	// ����ְ��
	void Sort_Emp();

	// ����ļ�
	void Clean_File();

	// ��������
	~WorkerManager();

	int m_EmpNum; // ��¼�ļ��е���������
	Worker** m_EmpArray; // Ա�������ָ�� **����ָ��ָ���ָ��
	bool m_FileIsEmpty; // ��־�ļ��Ƿ�Ϊ��
};