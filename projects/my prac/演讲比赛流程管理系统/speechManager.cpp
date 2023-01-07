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
	cout << "*********     ��ӭ�����ݽ�����С����     *********" << endl;
	cout << "*************    1. ��ʼ�ݽ�����     *************" << endl;
	cout << "*************    2. �鿴�����¼     *************" << endl;
	cout << "*************    3. ��ձ�����¼     *************" << endl;
	cout << "*************    0. �˳���ǰ����     *************" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}

void SpeechManager::exitMenu()
{
	cout << "���˳�����ӭ�´�����" << endl;
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
		string name = "ѡ��";
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
	// ��һ�ֿ�ʼ����
	// ��ǩ
	speechDraw();
	// ����
	speechContest();
	// �������
	speechResults();

	this->index++;

	// �ڶ��ֿ�ʼ����
	// ��ǩ
	speechDraw();
	// ����
	speechContest();
	// �������
	speechResults();
	// �����ļ�
	saveRecord();

	// ����
	this->init();
	this->createSpeaker();
	this->loadRecord();

	cout << "����������" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::speechDraw()
{
	vector<int> v;
	if (this->index == 1)
	{
		cout << "��һ�ֱ�����ʼ��ǩ��" << endl;
		cout << "----------------------" << endl;
		cout << "��ǩ���ݽ�˳�����£�" << endl;
		random_shuffle(this->v1.begin(), this->v1.end());
		v = v1;
	}
	else
	{
		cout << "�ڶ��ֱ�����ʼ��ǩ��" << endl;
		cout << "----------------------" << endl;
		cout << "��ǩ���ݽ�˳�����£�" << endl;
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
	cout << "�� <<" << (this->index == 1 ? "һ" : "��") << ">> �ֱ�����ʽ��ʼ" << endl;
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
		// ȥ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / d.size();

		this->speakers[*it].score[this->index - 1] = avg;
		groupScore.insert(make_pair(avg, *it));
		index++;

		if (index % 6 == 0)
		{
			cout << "��" << index / 6 << "���������£�" << endl;
			for (map<double, int>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "ѡ�ֱ�ţ�" << it->second << " ������" << this->speakers[it->second].name << " ѡ�ֵ÷֣�" << it->first << endl;
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
	cout << "�� <<" << (this->index == 1 ? "һ" : "��") << ">> �ֱ������" << endl;

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

	cout << "��" << (this->index == 1 ? "һ" : "��") << "�ֽ���ѡ��Ϊ��" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << " "
			"ѡ��������" << this->speakers[*it].name << " "
			"ѡ�ֳɼ���" << this->speakers[*it].score[this->index - 1] << endl;
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

	cout << "��¼�ѱ���" << endl;
	this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
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
		cout << "�ļ�Ϊ�ջ��ļ�������" << endl;
	}

	for (int i = 0; i < record.size(); i++)
	{
		cout << "��" << i + 1 << "��" <<
			"�ھ���ţ�" << record[i][0] << " �ɼ�Ϊ��" << record[i][1] << " "
			"�Ǿ���ţ�" << record[i][2] << " �ɼ�Ϊ��" << record[i][3] << " "
			"������ţ�" << record[i][4] << " �ɼ�Ϊ��" << record[i][5] << endl;
	}

	system("pause");
	system("cls");
}

void SpeechManager::clearAll()
{
	cout << "��ȷ��Ҫ�������������" << endl
		<< "1.ȷ��" << endl
		<< "2.����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		cout << "�������������" << endl;

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