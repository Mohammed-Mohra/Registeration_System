#include <iostream>
#include "Student_Data.h"
#include <fstream>
#include<string>
#include <exception>
using namespace std;

//int User_Option = { Registeration; Login;Delete };
//so this function prints messages to the user like 
//Maybe a better name would be setup function since this is the setup
//we leave this function when the user clarifies what he wants whether it is to login or register
//or delete


void Messages() {
	string name, password;//the name and password of the student

		Data Stud_File;// this object navigate through students' data
	
	
		char data;
	int i = 0;
	cout << "Hello\n" << "This is a registration system for basics of programming students"<<endl;
	
	while (i == 0) {
		cout << "For registration of new student, enter 1.\n For login to a student's data, enter 2"<<endl;
		cout << "If you want to exit the program press 3"<<endl;

		cin >> data;
		cin.ignore();//I use cin.ignore because sometimes I use getline function and cin.ignore() is important
		//when using getline after cin

		if (data != '3' && data != '1' && data != '2') {
			while (data != '0' && data != '1' && data != '2') {
				cout << "entered an invalid value. Please try again" << endl;
				cin >> data;
				cin.ignore();

			}
		}

		if (data == '3')//if data=2 then the program will break out of the loop and end
			break;

		if (data == '2') {
			//Data login_file;
			cout << "Please enter the students Neptune Code" << endl;
			getline(cin, name);
			cout << "Please enter the student's password" << endl;
			getline(cin, password);
			//the function will take the data and store them in name and password the 

			bool a = true;

			try {//this is for memory allocation exceptions
				a = Stud_File.login(name, password);
				//the function will return true if the login is successful
			}
			catch (...) {
				a = false;
				cout << "The file of the student doesnt exist"<<endl << "The student is removed from the system" << endl;
			}

			if (a == true) {
				cout << "Would you like to add anything to the file"<<endl<<"If yes enter 1 else enter 0"<<endl;
				cout << "If you want to delete the file please enter 2" << endl;
				char a;
				cin >> a;
				cin.ignore();
				if (a != '0' && a != '1' && a != '2') {
					while (a != '0' && a != '1' && a != '2') {
						cout << "Entered an invalid value. Please try again" << endl;
						cin >> a;
						cin.ignore();
					}
				}

				if (a == '1') {
					Stud_File.append(name, password);
				}
				else if (a == '2')
					Stud_File.Delete(name, password);
			}
		}
		else if (data == '1') {

			cout << "Please enter the neptune code of the student " << endl;
			getline(cin,name);
			
			cout << "Please enter the password now" << endl;
			getline(cin, password);
			
			//Data NewStud(name, password);
			bool a;
			try {
				a = Stud_File.registration(name, password);
			}
			catch (...) {
				cout << "Unfortunatly I could not register the student. You can try again"<<endl;
			}


			if (a == true) {
				cout << "The file was created successfully and the student is in the system now" << endl;
				cout << "Would you like to continue registration and filling the student's data" << endl << "If yes enter 1 else enter 0"<<endl;
				
				int a;
				cin >> a;
				cin.ignore();
				if (a == 1) {
					try { Stud_File.append(name, password); }
					catch (...) {
						cout <<"We could not add what you wrote to the file. We could not open the file"<<endl ;
					}
				}
			}

		}
	}
}


int main() { 
	//Data obj1("Mohammed","Moh194am43e");
	//
	Messages();

	return 0;
}
