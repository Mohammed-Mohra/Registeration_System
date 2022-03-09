#include "Student_Data.h"
#include <iostream>
#include<fstream>
#include<string>
#include "Exception.h"
#include <exception>
#include <sstream>

using namespace std;
//string Data::* pStudName = new string[50];
//string Data::*pPassword = NULL;
int Data::cursor = 0;
int Data::counter = 0;
Data::Data() {
	fstream new_file;
	new_file.open("index.txt", ios::in);
	if (!new_file)
		cout << "The file index doesnt exist. We cant find the students" << endl;;
	string file_read;
	//new_file << "this is working fine";
	int file_count = 0;

	while (getline(new_file, file_read)) {
		if (!file_read.empty())
			file_count++;
	}
	Data::counter = file_count / 2;

	new_file.close();
	new_file.open("index.txt", ios::in);

	try {
		pStudName = new string[file_count / 2];
		pPassword = new string[file_count / 2];
	}
	catch(...){
		cout << "Could not open the data file. You have to close the console and try again";

	}
	int n = 1;
	int i = 0;
	int k = 0;
	int s = 0;
	//getline(new_file, file_read);
	//cout << counter << endl;

	while (getline(new_file, file_read)) {
		if (!file_read.empty()) {
			if (i == n) {
				pPassword[k] = file_read;
				//	cout << pPassword[k]<<endl;
				i++;
				n = n + 2;
				k++;
			}
			else {
				pStudName[s] = file_read;
				s++;
				i++;
			}
		}
	}

	new_file.close();

}

Data::~Data() {
	delete[]pStudName;
	delete[]pPassword;
	pStudName = NULL;
	pPassword = NULL;

}


bool Data::login(const string name, const string password) {
	int a=0;
	fstream new_file;
	string x;
	new_file.open("index.txt", ios::in);
	int i = 0;
	int s = 1;
	int n = 1;
	//cout << counter << endl;
	while(getline(new_file,x)) {
		if(!x.empty()){

			if (i != s) {
				if (name == pStudName[i] && password == pPassword[i]) {
					a++;
					string file_read;
					fstream new_file(pStudName[i] + ".txt", ios::in);
					
					
					
					if (!new_file) {

						throw 0;

					}
					else {
						cout << "Here are the studnet's info" << endl<<endl;
						while (getline(new_file, file_read))
							cout << file_read << endl;
						cout <<endl<< "Login complete" << endl;
						new_file.close();
						return true;

					}

				}
			}
			s = i;
			if(n%2!=0)
				i++;
			n++;

		}		

		
		// then the function will call the student's info from the file
			
	}

	if (a == 0)
		cout << "There is no student with the information you gave" << endl;

	return false;

}

bool Data::append(const string name, const string password) {
	
	string file_append;
	string info;
	string ct1;
	char check_info[20];

	fstream new_file(name + ".txt", ios::app);
	if (!new_file)
		throw 0;
	char input;
	cout << "There is a list of what you can add\n Please select the number assigned to it and then add the value" << endl;
	
	cout << "Neptune Code: Press 1\n Control Test 1: Press 2\n Control Test 2: Press 3\nControl Test 3: Press 4\n Control Test 4: Press 5\n";
	cout << "Control Test 5: Press 6"<<endl;
	cout << "Midterm Score: Press 7\n Any other general notes: Press 8\n";
	cout << "If you dont want to add and go back to the main window click 0\n";
	cin >> input;
	cin.ignore();

	while (input != '0') {
		switch (input) {
		case '1':
			cout << "Neptune Code:" << endl;
			getline(cin, info);
			copyinfo(name + ".txt", "Neptune Code: ", info);
			break;
		case '2':
			cout << "Control Test 1:" << endl;
			getline(cin, info);
			copyinfo(name + ".txt", "Control Test 1: ", info);
			break;
		case '3':
			cout << "Control Test 2:" << endl;
			getline(cin, info);
			copyinfo(name + ".txt", "Control Test 2: ", info);
			break;
		case '4':
			cout << "Control Test 3:" << endl;
			getline(cin, info);
			copyinfo(name + ".txt","Control Test 3: ", info);
			break;
		case '5':
			cout << "Control Test 4:" << endl;
			getline(cin, info);
			copyinfo(name + ".txt", "Control Test 4: ", info);
			break;
		case '6':
			cout << "Control Test 5:" << endl;
			getline(cin, info);
			copyinfo(name + ".txt", "Control Test 5: ", info);
			break;
		case '7':
			cout << "Midterm Score:" << endl;
			getline(cin, info);
			copyinfo(name + ".txt", "Midterm Score:", info);
			break;
		case '8':
			cout << "Please enter your general notes:" << endl;
			getline(cin, info);
			copyinfo(name + ".txt", "Please enter your general notes:", info);
			break;

		}
		cout << "You can continue adding to the file by pressing the number assigned to it\n If you want to exist press 0 \n";
		cin >> input;
		cin.ignore();
	}
	//getline(cin, file_append);
	//new_file << file_append<<endl;
	//cout << "The adding to the file is complete"<<endl;
	return true;
}

bool Data::copyinfo(string filename,string info1,string info2) {
	
	int a, b,c;
	a = b =c= 0;
	string a1, a2;
	fstream temp, temp2;
	string lines;
	int check_line = 0;
	temp.open(filename, ios::in);
	
	temp2.open("temp.txt", ios::out);
	for (int i = 0;getline(temp, lines);i++) {
		istringstream is1(lines);
		istringstream is2(info1);
		while (is1 >> a1&& is2>>a2) {
			a++;
			if (a1 == a2)
				b++;
		}
		if (a == b) {
			temp2 << info1+" " + info2 << endl;
			a = b = 0;
			c = 1;
			continue;
		}
		else {
			temp2 << lines << endl;
		}
		a = b = 0;

	}
	if(c==0)
		temp2 << info1+" " + info2 << endl;
	temp.close();
	temp2.close();
	temp.open(filename, ios::out);
	temp2.open("temp.txt", ios::in);
	for (int i = 0;getline(temp2, lines);i++) {
		temp << lines << endl;
	}
	temp.close();
	temp2.close();
	remove("temp.txt");
	return true;


}



bool Data::registration(string name,string password) {
	Data::counter++;
	string studname;
	if (Data::counter == 0) {//counter should be 0 here
		fstream new_file;
		new_file.open("index.txt", ios::out);
		pPassword[0] = password;
		new_file << name;
		new_file << password;
		new_file.close();
		return true;
		return true;

	}


	/*this is basically creating a new students so it will be added to the array when
	the user chooses to register
	*/


	else {
		//	StudNum++;

		string* ptemp1 = new string[counter];
		string* ptemp2 = new string[counter];
		for (int i = 0;i < counter - 1;i++) {
			ptemp1[i] = pStudName[i];
			ptemp2[i] = pPassword[i];
		}
		delete[] pStudName;
		delete[] pPassword;
		ptemp1[counter - 1] = name;
		ptemp2[counter - 1] = password;
		pStudName = new string[counter];
		pPassword = new string[counter];
		for (int i = 0;i < counter;i++) {
			pStudName[i] = ptemp1[i];
			pPassword[i] = ptemp2[i];
		}
		delete[] ptemp1;
		delete[] ptemp2;
		ptemp1 = NULL;
		ptemp2 = NULL;
		fstream new_file;
		new_file.open("index.txt", ios::app);
		if (Data::cursor == 0)
			new_file << endl<<name<<endl<<password<<endl;
		else {
			new_file << name << endl;
			new_file << password << endl;
		}
		Data::cursor++;
		new_file.close();
	}
	//cout << pStudName[0];
	string neptune;
	fstream new_file;
	fstream new_file1;
	new_file.open(pStudName[Data::counter - 1] + ".txt", ios::in);
	if (new_file) {
		cout << "This file is already in the system\n";
		new_file.close();
		return false;
	}
		
	else if (!new_file) {
		cout << "Please enter the name of the student\n";
		getline(cin, studname);
		new_file.open(pStudName[Data::counter - 1] + ".txt", ios::out);
		if (!new_file)
			throw 1;
		new_file << "Neptune Code: " << pStudName[Data::counter - 1] << endl << "Passowrd: " << pPassword[Data::counter - 1] << endl;
		new_file << "Name: " << studname << endl;
		new_file.close();
	}
	
	/*this function will take the name and the password and from the name index can
	locate the student information*/
	cout << "Registration is complete"<<endl;
	return true;

}


bool Data::Delete(string name, string password) {
	int namelength;
	namelength = name.length();
	char* a = new char[namelength+5];
	for ( int i = 0;i < name.length()+1;i++) {
		
		if (i == name.length()) {
			a[i] = '.';
			a[i + 1] = 't';
			a[i + 2] = 'x';
			a[i + 3] = 't';
			a[i + 4] = '\0';
		}
		else if(i<name.length()) {
			a[i] = name.at(i);
		}

	}
	remove(a);
	delete[] a;
	return true;

	
}






