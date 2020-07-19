
class book{
	char bno[6];
	char bookName[50];
	char authName[20];
	int state;
public:
	int id;
	void create_book();
	void show_book();
	void modify_book();
	char* retbno();
	void report();
	void setstate();
	int retstate();
	void resetstate();
};