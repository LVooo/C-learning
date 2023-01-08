#include "orderFile.h"

void insertValue(string s, map<string, string>& m)
{
	string key;
	string value;

	int pos = s.find(":");
	if (pos != -1)
	{
		key = s.substr(0, pos);
		value = s.substr(pos + 1, s.size() - pos - 1);
		m.insert(make_pair(key, value));
	}
}

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	  
	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->size = 0;

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		map<string, string> m;

		insertValue(date, m);
		insertValue(interval, m);
		insertValue(stuId, m);
		insertValue(stuName, m);
		insertValue(roomId, m);
		insertValue(status, m);

		this->orderData.insert(make_pair(this->size, m));
		this->size++;
	}

	//for (map<int, map<string, string>>::iterator it = orderData.begin(); it != orderData.end();it++)
	//{
	//	cout << "key = " << it->first << " value = " << endl;
	//	for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
	//	{
	//		cout << mit->first << " " << mit->second << " ";
	//	}
	//	cout << endl;
	//}

}

void OrderFile::updateOrder()
{
	if (size == 0)
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);

	for (int i = 0; i < size; i++)
	{
		ofs << "date:" << this->orderData[i]["date"] << " ";
		ofs << "interval:" << this->orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->orderData[i]["roomId"] << " ";
		ofs << "status:" << this->orderData[i]["status"] << " ";
	}

	ofs.close();
}