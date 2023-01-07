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
	// 首轮容器
	vector<int> v1;

	// 第二轮容器
	vector<int> v2;

	// 最终胜利容器
	vector<int> victory;

	// 存放演讲人
	map<int, Speaker> speakers;

	// 轮数
	int index;

	// 文件判空
	bool fileIsEmpty;

	// 往届记录
	map<int, vector<string>> record;
};