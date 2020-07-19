#include "stdafx.h"
#include <fstream>
#include <string.h>
#include <iomanip>
#include <iostream>
#include "book.h"

using  namespace std;

void book::create_book(){
	cout << "\nNEW BOOK ENTRY...\n";
	cout << "\nEnter Book Number : ";
	cin >> bno;
	cout << "\nEnter Book ID : ";
	cin >> id;
	cout << "\n\nEnter Name of the Book : ";
	cin.get();
	cin.getline(bookName, 50);
	cout << "\n\nEnter Author's name : ";
	cin.getline(authName, 20);
	state = 0;
	cout << "\n\n\nBook Created...";
	cin.get();
}

void book::show_book(){
	cout << "\nBook number : " << bno;
	cout << "\nBook Name : " << bookName;
	cout << "\nAuthor Name : " << authName;
	cout << "\nBook state: " << state;
}

void book::modify_book(){
	cout << "\nBook number : " << bno;
	cout << "\nModify Book Name : ";
	cin.get();
	cin.getline(bookName, 50);
	cout << "\nModify Author's Name : ";
	cin.get();
	cin.getline(authName, 20);
}

char* book::retbno(){
	return bno;
}

void book::report(){
	cout << bno << setw(30) << bookName<< setw(30)
		<< authName << setw(12) << state << endl;
}

void book::setstate(){
	state = 1;
}

int book::retstate(){
	return state;
}

void book::resetstate(){
	state = 0;
}