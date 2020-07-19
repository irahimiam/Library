#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include "book.h"
#include "student.h"

using  namespace std;

const int size = 100;
book b[size];
student s[size];

void admin_menu();
void write_book();
void write_student();
void display_spb(char []);
void display_sps(char []);
void display_alls();
void display_allb();
void modify_book();
void modify_student();
void delete_student();
void delete_book();
void book_issue();
void book_deposit();
void book_reservation();

int i = 0;
int a = 0, c = 0;

void main(){

	fstream f1;
	f1.open("student.dat", ios::in | ios::out | ios::app | ios::binary);
	int k = 0;
	while (k < size && f1.eof() != 1){
		f1.read((char *)&s[k], sizeof(s[k]));
		k++;
	}
	a = k;
	
	f1.close();
	remove("student.dat");

	fstream f;
	f.open("book.dat", ios::in | ios::out | ios::app | ios::binary);
	int j = 0;
	while (j < size && f.eof() != 1){
		f.read((char *)&b[j], sizeof(b[j]));
		j++;
	}
	c = j;
	
	f.close();
	remove("book.dat");

	char ch;
	do{
		std::system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t(1) BOOK ISSUE";
		cout << "\n\n\t(2) BOOK DEPOSIT";
		cout << "\n\n\t(3) BOOK RESERVATION";
		cout << "\n\n\t(4) ADMINISTRATOR MENU";
		cout << "\n\n\t(5) SAVE & EXIT";
		cout << "\n\n\tPlease Select Your Option (1-5) ";
		cin >> ch;

		switch (ch){
		case '1':
			book_issue();
			break;
		case '2':
			book_deposit();
			break;
		case '3':
			book_reservation();
			break;
		case '4':
			admin_menu();
			break;
		case '5':
		{
					fstream f;
					f.open("book.dat", ios::out | ios::binary | ios::app);
					int x = 0;
					while (x < size){
						if (b[x].id != 0){
							f.write((char *)&b[x], sizeof(b[x]));
						}
						x++;
					}
					f.close();

					fstream f1;
					
					f1.open("student.dat", ios::out | ios::binary | ios::app);
					int z = 0;
					while (z < size){
						if (s[z].id != 0){
							f1.write((char *)&s[z], sizeof(s[z]));
						}
						z++;
					}
					f1.close();
					exit(0);
		}
			
		default: 
			cout << "\a";
		}
	} while (ch != '5');
}
/////////////////////////////////////
void admin_menu(){
	std::system("cls");
	int ch2;
	cout << "\n\n\n\tADMINISTRATOR MENU";
	cout << "\n\n\t(1) CREATE STUDENT RECORD";
	cout << "\n\n\t(2) DISPLAY ALL STUDENTS RECORD";
	cout << "\n\n\t(3) DISPLAY SPECIFIC STUDENT RECORD ";
	cout << "\n\n\t(4) MODIFY STUDENT RECORD";
	cout << "\n\n\t(5) DELETE STUDENT RECORD";
	cout << "\n\n\t(6) CREATE BOOK ";
	cout << "\n\n\t(7) DISPLAY ALL BOOKS ";
	cout << "\n\n\t(8) DISPLAY SPECIFIC BOOK ";
	cout << "\n\n\t(9) MODIFY BOOK ";
	cout << "\n\n\t(10) DELETE BOOK ";
	cout << "\n\n\t(11) BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-11) ";
	cin >> ch2;
	switch (ch2){
	case 1:
		std::system("cls");
		write_student();
		break;
	case 2:
		display_alls();
		break;
	case 3:
		char num[6];
		std::system("cls");
		cout << "\n\n\tPlease Enter The Admission No. ";
		cin >> num;
		display_sps(num);
		break;
	case 4:
		modify_student();
		break;
	case 5:
		delete_student();
		break;
	case 6:
		std::system("cls");
		write_book();
		break;
	case 7:
		display_allb();
		break;
	case 8:
		char num1[6];
		std::system("cls");
		cout << "\n\n\tPlease Enter The book No. ";
		cin >> num1;
		display_spb(num1);
		break;
	case 9:
		modify_book();
		break;
	case 10:
		delete_book();
		break;
	case 11: 
		main();
	default: 
		cout << "\a";
	}
	admin_menu();
}
//////////////////////////////////////////////
void write_book(){
	char ch;

	do{
		std::system("cls");
		b[c].create_book();
		c++;
		cout << "\n\nDo you want to add more books...(y/n?)";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}

void write_student(){
	char ch;
	do{
		s[a].create_student();
		a++;
		cout << "\n\nDo you want to add more students...(y/n?)";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}
////////////////////////////////////////////
void display_spb(char n[]){
	cout << "\nBOOK DETAILS\n";
	int flag = 0;
	i = 0;
	while (i < size){
		if (strcmp(b[i].retbno(), n) == 0){
			b[i].show_book();
			cin.get();
			flag = 1;
		}
		i++;
	}
	if (flag == 0)
		cout << "\n\nBook does not exist";
	cin.get();
}

void display_sps(char n[]){
	cout << "\nSTUDENT DETAILS\n";
	int flag = 0;
	i = 0;

	while (i < size){
		if ((strcmp(s[i].retadmno(), n) == 0)){
			s[i].show_student();
			cin.get();
			flag = 1;
		}
		i++;
	}
	if (flag == 0)
		cout << "\n\nStudent does not exist";
	cin.get();
}
/////////////////////////////////////////////
void modify_book(){
	char n[6];
	i = 0;
	int flag = 0;
	std::system("cls");
	cout << "\n\n\tMODIFY BOOK REOCORD.... ";
	cout << "\n\n\tEnter The book no. of The book";
	cin >> n;
	cin.get();

	while (i < size){
		if (strcmp(b[i].retbno(), n) == 0){
			b[i].show_book();
			cout << "\nEnter New Details of Book" << endl;
			b[i].modify_book();
			flag = 1;
			cin.get();
		}
		i++;
	}
	if (flag == 0)
		cout << "\n\nBook does not exist";
	else
		cout << "\n\n\t Record Updated";
	cin.get();
}

void modify_student(){
	char n[6];
	i = 0;
	int flag = 0;
	std::system("cls");
	cout << "\n\n\tMODIFY BOOK REOCORD.... ";
	cout << "\n\n\tEnter The Student no. of The Student";
	cin >> n;
	cin.get();

	while (i < size){
		if (strcmp(s[i].retadmno(), n) == 0){
			s[i].show_student();
			cout << "\nEnter New Details of Student" << endl;
			s[i].modify_student();
			flag = 1;
			cin.get();
		}
		i++;
	}
	if (flag == 0)
		cout << "\n\nStudent does not exist";
	else
		cout << "\n\n\t Record Updated";
	cin.get();
}
///////////////////////////////////////////////
void delete_student(){
	char n[6];
	int flag = 0;
	i = 0;
	std::system("cls");
	cout << "\n\n\n\tDELETE STUDENT...";
	cout << "\n\nEnter The admission no. of the Student You Want To Delete : ";
	cin >> n;
	cin.get();

	while (i < size){
		if (strcmp(s[i].retadmno(), n) == 0){
			s[i].id = 0;
			flag = 1;
		}
		i++;
	}
	if (flag == 1)
		cout << "\n\n\tRecord Deleted ..";
	else
		cout << "\n\nRecord not found";
	cin.get();
}

void delete_book(){
	char n[6];
	int flag = 0;
	i = 0;
	std::system("cls");
	cout << "\n\n\n\tDELETE BOOK ...";
	cout << "\n\nEnter Book number of Book to Delete : ";
	cin >> n;
	cin.get();

	while (i < size){
		if (strcmp(b[i].retbno(), n) == 0){
			b[i].id = 0;
			flag = 1;
		}
		i++;
	}
	if (flag == 1)
		cout << "\n\n\tRecord Deleted ..";
	else
		cout << "\n\nRecord not found";
	cin.get();
}
/////////////////////////////////////////////
void display_alls(){
	std::system("cls");
	i = 0;
	cout << "\n\n\t\tSTUDENT LIST\n\n";
	cout << "=======================================================================\n";
	cout << setw(6) << "Admission No." << setw(10) << "Name" << setw(15) << "Book Issued" << setw(12) << "state" << setw(12) << "Reserve\n";
	cout << "=======================================================================\n";

	while (i < size){
		if (s[i].id != 0){
			s[i].report();
		}
		i++;
	}
	cin.get();
	cin.get();
}

void display_allb(){
	std::system("cls");
	i = 0;
	cout << "\n\n\t\tBook LIST\n\n";
	cout << "=============================================================================\n";
	cout << "Book Number" << setw(20) << "Book Name" << setw(30) << "Author" << setw(15) << "State\n";
	cout << "=============================================================================\n";

	while (i < size) {
		if (b[i].id != 0){
			b[i].report();
		}
		i++;
	}
	cin.get();
	cin.get();
}
///////////////////////////////////////////
void book_issue(){
	char sn[6];
	char bn[6];
	int found = 0, flag = 0;
	std::system("cls");
	cout << "\n\nBOOK ISSUE ...";
	cout << "\n\n\tEnter Student's Admission number : ";
	cin >> sn;
	cin.get();

	i = 0;
	int m = 0;

	while (i < size){
		if ((strcmp(s[i].retadmno(), sn) == 0)){
			flag = 1;
			m = i;
		}
		i++;
	}
	if (flag == 0){
		cout << "\n\nStudent does not exist";
		cin.get();
	}
	else
	{
		switch (s[m].retstate())
		{
		case 1:
		{
				  if (s[m].rettoken() < 3){
					  cout << "\n\n\tEnter Book number : ";
					  cin >> bn;
					  cin.get();

					  int flag3 = 0;
					  i = 0;
					  int n = 0;
					  while (i < size){
						  if (strcmp(b[i].retbno(), bn) == 0){
							  flag3 = 1;
							  n = i;
						  }
						  i++;
					  }
					  if (flag3 == 0){
						  cout << "\n\nBook does not exist";
						  cin.get();
					  }
					  else{
						  if (b[n].retstate() == 0){
							  b[n].show_book();
							  s[m].addtoken();
							  s[m].getstbno(b[n].retbno());

							  cout << "\n\n\t Book issued successfully\n";
							  cout << "\nPlease Note: Write the current date in backside of your book";
							  cout << " \n and submit within 15 days fine $. 1 for each day \n after 15 days period";
						  }
						  else{
							  cout << "Book under Reservation...";
						  }
						  if (b[n].retstate() == 1 && strcmp(b[n].retbno(), s[m].retstrbno()) == 0){
							  b[n].show_book();
							  s[m].addtoken();
							  s[m].getstbno(b[n].retbno());
							  b[n].resetstate();
							  s[m].resetres();

							  cout << "\n\n\t Book issued successfully\n";
							  cout << "\nPlease Note: Write the current date in backside of your book";
							  cout << " \n and submit within 15 days fine $. 1 for each day \n after 15 days period";
						  }
					  }

				  }
				  else
					 cout << "You have not returned the last book  ";

		}
			break;

		case 2:
		{
				  if (s[m].rettoken() < 4){
					  cout << "\n\n\tEnter Book number : ";
					  cin >> bn;
					  cin.get();

					  int flag3 = 0;
					  i = 0;
					  int n = 0;
					  while (i < size){
						  if (strcmp(b[i].retbno(), bn) == 0){
							  flag3 = 1;
							  n = i;
						  }
						  i++;
					  }
					  if (flag3 == 0){
						  cout << "\n\nBook does not exist";
						  cin.get();
					  }
					  else{
						  if (b[n].retstate() == 0){
							  b[n].show_book();
							  s[m].addtoken();
							  s[m].getstbno(b[n].retbno());

							  cout << "\n\n\t Book issued successfully\n";
							  cout << "\nPlease Note: Write the current date in backside of your book";
							  cout << " \n and submit within 15 days fine $. 1 for each day \n after 15 days period";
						  }
						  else{
							  cout << "Book under Reservation...";
						  }
						  if (b[n].retstate() == 1 && strcmp(b[n].retbno(), s[m].retstrbno()) == 0){
							  b[n].show_book();
							  s[m].addtoken();
							  s[m].getstbno(b[n].retbno());
							  b[n].resetstate();
							  s[m].resetres();

							  cout << "\n\n\t Book issued successfully\n";
							  cout << "\nPlease Note: Write the current date in backside of your book";
							  cout << " \n and submit within 15 days fine $. 1 for each day \n after 15 days period";
						  }
					  }

				  }
				  else
					  cout << "You have not returned the last book  ";
		}
			break;

		case 3:
		{
				  if (s[m].rettoken() < 6){
					  cout << "\n\n\tEnter Book number : ";
					  cin >> bn;
					  cin.get();

					  int flag3 = 0;
					  i = 0;
					  int n = 0;
					  while (i < size){
						  if (strcmp(b[i].retbno(), bn) == 0){
							  flag3 = 1;
							  n = i;
						  }
						  i++;
					  }
					  if (flag3 == 0){
						  cout << "\n\nBook does not exist";
						  cin.get();
					  }
					  else{
						  if (b[n].retstate() == 0){
							  b[n].show_book();
							  s[m].addtoken();
							  s[m].getstbno(b[n].retbno());

							  cout << "\n\n\t Book issued successfully\n";
							  cout << "\nPlease Note: Write the current date in backside of your book";
							  cout << " \n and submit within 15 days fine $. 1 for each day \n after 15 days period";
						  }
						  else{
							  cout << "Book under Reservation...";
						  }
						  if (b[n].retstate() == 1 && strcmp(b[n].retbno(), s[m].retstrbno()) == 0){
							  b[n].show_book();
							  s[m].addtoken();
							  s[m].getstbno(b[n].retbno());
							  b[n].resetstate();
							  s[m].resetres();

							  cout << "\n\n\t Book issued successfully\n";
							  cout << "\nPlease Note: Write the current date in backside of your book";
							  cout << " \n and submit within 15 days fine $. 1 for each day \n after 15 days period";
						  }
					  }

				  }
				  else
					  cout << "You have not returned the last book  ";
		}
			break;
		}
	}
	cin.get();
}
/////////////////////////////////////////
void book_deposit()
{
	char sn[6];
	int found = 0, flag = 0, day, fine;
	std::system("cls");
	cout << "\n\nBOOK DEPOSIT ...";
	cout << "\n\n\tEnter Student’s Admission number : ";
	cin >> sn;
	cin.get();

	i = 0;
	int m = 0;
	while (i < size){
		if ((strcmp(s[i].retadmno(), sn) == 0)){
			flag = 1;
			m = i;
		}
		i++;
	}
	if (flag == 0)
		cout << "\n\nStudent does not exist";

	if (s[m].rettoken() != 0){
		i = 0;
		while ( i < size){
			if (strcmp(b[i].retbno(), s[m].retstbno()) == 0){
				b[i].show_book();
				cout << "\n\nBook deposited in no. of days : ";
				cin >> day;
				cin.get();

				if (day > 15){
					fine = (day - 15) * 1;
					cout << "\n\nFine to deposited is $. " << fine;
				}
				s[m].resettoken();
				cout << "\n\n\t Book deposited successfully";
				cin.get();
			}
			i++;
		}
	}
	else 
		cout << "No book is issued..please check!!";

	cin.get();
}
/////////////////////////////////////////
void book_reservation(){
	char sn[6], bn[6];
	int found = 0, flag = 0;
	std::system("cls");
	cout << "\n\nBOOK RESERVATION ...";
	cout << "\n\n\tEnter Student's Admission number : ";
	cin >> sn;
	cin.get();

	i = 0;
	int m = 0;
	while (i < size){
		if ((strcmp(s[i].retadmno(), sn) == 0)){
			cin.get();
			flag = 1;
			m = i;
		}
		i++;
	}
	if (flag == 0)
		cout << "\n\nStudent does not exist";
	else{
		switch (s[m].retstate())
		{
		case 1:
		{
				  if (s[m].rettoken() < 3){
					  cout << "\n\n\tEnter Book number : ";
					  cin >> bn;
					  cin.get();

					  i = 0;
					  int n = 0;
					  while (i < size){
						  if (strcmp(b[i].retbno(), bn) == 0){
							  b[i].show_book();
							  cin.get();
							  flag = 1;
							  n = i;
						  }
						  i++;
					  }
					  if (flag == 0)
						  cout << "\n\nBook does not exist";
					  else{
						  if (b[n].retstate() == 0 && s[m].retres() == 0){
							  b[n].setstate();
							  //b[n].show_book();
							  s[m].getstrbno(b[n].retbno());
							  s[m].setres();
							  cout << "\n\n\t Book Reserved successfully\n";
						  }
						  else
							  cout << "Book is Under Reservation...\n";
					  }

				  }
				  else
					  cout << "You have not returned the last book ";
		}
			break;

		case 2:
		{
				  if (s[m].rettoken() < 4){
					  cout << "\n\n\tEnter Book number : ";
					  cin >> bn;
					  cin.get();

					  i = 0;
					  int n = 0;
					  while (i < size){
						  if (strcmp(b[i].retbno(), bn) == 0){
							  b[i].show_book();
							  cin.get();
							  flag = 1;
							  n = i;
						  }
						  i++;
					  }
					  if (flag == 0)
						  cout << "\n\nBook does not exist";
					  else{
						  if (b[n].retstate() == 0 && s[m].retres() == 0){
							  b[n].setstate();
							  //b[n].show_book();
							  
							  s[m].getstrbno(b[n].retbno());
							  s[m].setres();
							  cout << "\n\n\t Book Reserved successfully\n";
						  }
						  else
							  cout << "Book is Under Reservation...\n";
					  }

				  }
				  else
					  cout << "You have not returned the last book ";

		}
			break;

		case 3:
		{
				  if (s[m].rettoken() < 6){
					  cout << "\n\n\tEnter Book number : ";
					  cin >> bn;
					  cin.get();

					  i = 0;
					  int n = 0;
					  while (i < size){
						  if (strcmp(b[i].retbno(), bn) == 0){
							  b[i].show_book();
							  cin.get();
							  flag = 1;
							  n = i;
						  }
						  i++;
					  }
					  if (flag == 0)
						  cout << "\n\nBook does not exist";
					  else{
						  if (b[n].retstate() == 0 && s[m].retres() == 0){
							  b[n].setstate();
							 // b[n].show_book();
							  s[m].getstrbno(b[n].retbno());
							  s[m].setres();
							  cout << "\n\n\t Book Reserved successfully\n";
						  }
						  else
							  cout << "Book is Under Reservation...\n";
					  }

				  }
				  else
					  cout << "You have not returned the last book ";
		}
			break;
		}
	}
	cin.get();
}
/////////////////////////////////////////