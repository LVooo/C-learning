#include "speechManager.h"
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>

SpeechManager::SpeechManager()
{
	init();
	createSpeaker();
	loadRecord();
}

void SpeechManager::showMenu()
{
	cout << "**************************************************" << endl;
	cout << "*********     欢迎来到演讲比赛小程序     *********" << endl;
	cout << "*************    1. 开始演讲比赛     *************" << endl;
	cout << "*************    2. 查看往届记录     *************" << endl;
	cout << "*************    3. 清空比赛记录     *************" << endl;
	cout << "*************    0. 退出当前程序     *************" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}

void SpeechManager::exitMenu()
{
	cout << "已退出，欢迎下次再来" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::init()
{
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->speakers.clear();

	this->index = 1;
	this->record.clear();
}

void  SpeechManager::createSpeaker()
{
	string nameSpeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSpeed.size(); i++)
	{
		string name = "选手";
		name += nameSpeed[i];
		Speaker sp;
		sp.name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.score[j] = 0;
		}
		v1.push_back(10001 + i);
		speakers.insert(make_pair(10001 + i, sp));
	}
}

void SpeechManager::startSpeech()
{
	// 第一轮开始比赛
	// 抽签
	speechDraw();
	// 评分
	speechContest();
	// 给出结果
	speechResults();

	this->index++;

	// 第二轮开始比赛
	// 抽签
	speechDraw();
	// 评分
	speechContest();
	// 给出结果
	speechResults();
	// 保存文件
	saveRecord();

	// 重置
	this->init();
	this->createSpeaker();
	this->loadRecord();

	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::speechDraw()
{
	vector<int> v;
	if (this->index == 1)
	{
		cout << "第一轮比赛开始抽签：" << endl;
		cout << "----------------------" << endl;
		cout << "抽签后演讲顺序如下：" << endl;
		random_shuffle(this->v1.begin(), this->v1.end());
		v = v1;
	}
	else
	{
		cout << "第二轮比赛开始抽签：" << endl;
		cout << "----------------------" << endl;
		cout << "抽签后演讲顺序如下：" << endl;
		random_shuffle(this->v2.begin(), this->v2.end());
		v = v2;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "----------------------" << endl;

	system("pause");
}

void SpeechManager::speechContest()
{
	cout << "第 <<" << (this->index == 1 ? "一" : "二") << ">> 轮比赛正式开始" << endl;
	cout << endl;
	multimap<double, int, greater<int>> groupScore;
	int index = 0;

	vector<int> v;
	if (this->index == 1)
	{
		v = v1;
	}
	else
	{
		v = v2;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<int>());
		// 去掉最高分和最低分
		d.pop_back();
		d.pop_front();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / d.size();

		this->speakers[*it].score[this->index - 1] = avg;
		groupScore.insert(make_pair(avg, *it));
		index++;

		if (index % 6 == 0)
		{
			cout << "第" << index / 6 << "组名次如下：" << endl;
			for (map<double, int>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "选手编号：" << it->second << " 姓名：" << this->speakers[it->second].name << " 选手得分：" << it->first << endl;
			}

			int count = 0;
			if (this->index == 1)
			{
				for (map<double, int>::iterator it = groupScore.begin(); it != groupScore.end(), count < 3; it++, count++)
				{
					this->v2.push_back(it->second);
				}
			}
			else
			{
				for (map<double, int>::iterator it = groupScore.begin(); it != groupScore.end(), count < 3; it++, count++)
				{
					this->victory.push_back(it->second);
				}
			}

			groupScore.clear();
			cout << endl;
		}
	}
	cout << "第 <<" << (this->index == 1 ? "一" : "二") << ">> 轮比赛完毕" << endl;

	system("pause");
	system("cls");
}

void SpeechManager::speechResults()
{
	vector<int> v;
	if (this->index == 1)
	{
		v = v2;
	}
	else
	{
		v = victory;
	}

	cout << "第" << (this->index == 1 ? "一" : "二") << "轮晋级选手为：" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号：" << *it << " "
			"选手姓名：" << this->speakers[*it].name << " "
			"选手成绩：" << this->speakers[*it].score[this->index - 1] << endl;
	}

	system("pause");
	system("cls");
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	for (vector<int>::iterator it = victory.begin(); it != victory.end(); it++)
	{
		ofs << *it << ","
			<< speakers[*it].score[1] << ",";
	}

	ofs << endl;
	ofs.close();

	cout << "记录已保存" << endl;
	this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	ifs.putback(ch);
	this->fileIsEmpty = false;

	string data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string> v;

		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string tmp = data.substr(start, pos - start);
			v.push_back(tmp);
			start = pos + 1;
		}

		this->record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();
}

void SpeechManager::showRecord()
{
	if (fileIsEmpty != false)
	{
		cout << "文件为空或文件不存在" << endl;
	}

	for (int i = 0; i < record.size(); i++)
	{
		cout << "第" << i + 1 << "届" <<
			"冠军编号：" << record[i][0] << " 成绩为：" << record[i][1] << " "
			"亚军编号：" << record[i][2] << " 成绩为：" << record[i][3] << " "
			"季军编号：" << record[i][4] << " 成绩为：" << record[i][5] << endl;
	}

	system("pause");
	system("cls");
}

void SpeechManager::clearAll()
{
	cout << "你确定要清除所有数据吗？" << endl
		<< "1.确认" << endl
		<< "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "已清除所有数据" << endl;

		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->init();
		this->createSpeaker();
		this->loadRecord();
	}

	system("pause");
	system("cls");
}

SpeechManager::~SpeechManager()
{

}