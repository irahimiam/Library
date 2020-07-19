#include "stdafx.h"
#include <fstream>
#include <string.h>
#include <iomanip>
#include <iostream>
#include "student.h"

using  namespace std;

void student::create_student(){
	std::system("cls");
	cout << "\nNEW STUDENT ENTRY...\n";
	cout << "\nEnter Admission number : ";
	cin.get();
	cin >> admno;
	cout << "\nEnter studnet ID : ";
	cin >> id;
	cout << "\n\nEnter Name of Student : ";
	cin.get();
	cin.getline(name, 20);
	cout << "\nEnter your state:-\n";
	cout << "State 1:Bd \nState 2:Md \nState 3:Ph.D \n";
	cin >> state;
	token = 0;
	res = 0;
	stbno[0] = '\0';
	cout << "\n\nStudent Record Created..";
}

void student::show_student(){
	cout << "\nAdmission number : " << admno;
	cout << "\nStudent Name : ";
	cout << name;
	cout << "\nNumber of Book(s) issued : " << token;
	cout << "\nReservation state: " << res;

	if (token != 0)
		cout << "\nBook No " << stbno;
}

void student::modify_student(){
	cout << "\n STUDENT ENTRY...\n";
	cout << "\n\nEnter Name of Student : ";
	cin.get();
	cin.getline(name, 20);
	cout << "Enter your state:-\n";
	cout << "State 1:Bd \nState 2:Md \nState 3:Ph.D \n";
	cin >> state;
	cin.get();
	cout << "\n\nStudent Record Updated...";
	cout << "\nAdmission number : " << admno;
	cout << "\nModify Student Name : " << name;
	cout << "\nState : " << state;
	cout << "\nNo. of Book Issue : " << token;
}

char* student::retadmno(){
	return admno;
}

char* student::retstbno(){
	return stbno;
}

char * student::retstrbno(){
	return strbno;
}

int student::rettoken(){
	return token;
}

void student::addtoken(){
	token++;
}

void student::resettoken(){
	token = (token > 0) ? (token-1) : 0;
}

void student::getstbno(char t[]){
	strcpy(stbno, t);
}

void student::getstrbno(char t[]){
	strcpy(strbno, t);
}

void student::report(){
	//cout.setf(ios::left);
	cout << setw(6) << admno << setw(18)
		<< name << setw(10) << token << setw(12) << state << setw(12) << res << endl;
}

int student::retstate(){
	return state;
}

int student::retres(){
	return res;
}

void student::setres(){
	res = 1;
}

void student::resetres(){
	res = 0;
}

