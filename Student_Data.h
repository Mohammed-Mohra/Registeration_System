#include <iostream>
using namespace std;

class Data {
private:
		;
	static int cursor ;
	static int counter;
	 string* pStudName ;
	 string* pPassword;

public:
	~Data();
	Data();
	bool Delete(string name,string password);
	bool login(const string, const string);
	bool registration(string name,string password);
	bool append(const string name,const string password);
	bool copyinfo(string filename,string info1,string info2);
	void count();
};

