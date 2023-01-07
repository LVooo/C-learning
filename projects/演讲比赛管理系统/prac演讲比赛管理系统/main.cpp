#include <iostream>
#include "speechManager.h"
using namespace std;

void test01(SpeechManager &sm)
{
	for (int i = 0; i < 12; i++)
	{
		cout << "����ѡ�֣�" << sm.v1[i] << " " << sm.speakers[sm.v1[i]].name << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	SpeechManager sm;
	int select = 0;

	while (true)
	{
		sm.showMenu();

		cout << "����������ѡ��";
		cin >> select;

		switch (select)
		{
		case 1:
			sm.startSpeech();
			break;
		case 2:
			sm.showRecord();
			break;
		case 3:
			sm.clearAll();
			break;
		case 0:
			sm.exitMenu();
			break;
		default:
			system("pause");
			break;
		}
	}

	system("pause");
	return 0;
}