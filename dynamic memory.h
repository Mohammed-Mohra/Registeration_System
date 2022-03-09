#include <iostream>
//#include "Student_Data.h"
using namespace std;

class Dynamic_Mem {
	string* pStudName;
	string* pPassword;
	static int counter ;

public:
	Dynamic_Mem() {
		pStudName = new string[50];
		pPassword = new string[50];
	}
	friend class Data;
};




#pragma once
