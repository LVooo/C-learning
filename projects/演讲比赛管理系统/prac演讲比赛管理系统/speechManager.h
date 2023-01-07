#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"
using namespace std;

class SpeechManager
{
public:
	SpeechManager();

	void showMenu();

	void exitMenu();

	void init();

	void createSpeaker();

	void startSpeech();

	void speechDraw();

	void speechContest();

	void speechResults();

	void saveRecord();

	void loadRecord();

	void showRecord();

	void clearAll();

	~SpeechManager();

public:
	// ��������
	vector<int> v1;

	// �ڶ�������
	vector<int> v2;

	// ����ʤ������
	vector<int> victory;

	// ����ݽ���
	map<int, Speaker> speakers;

	// ����
	int index;

	// �ļ��п�
	bool fileIsEmpty;

	// �����¼
	map<int, vector<string>> record;
};