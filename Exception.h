#include <string>
#include <iostream>
#include <exception>
using namespace std;


class File_Register:public exception{
	virtual const char* what();

} ;
class Mem_Alloc :public exception{
	virtual const char* what();
};
class Login :public exception {
	virtual const char* what();

};

#pragma once
