
class student{
private:
	char admno[6]; //Admission number
	char name[20]; //Name of the student
	char stbno[6]; //Student Book number
	char strbno[6];//student Book Reserve number
	int token;
	int state;
	int res;
public:
	int id;
	//void setadmno();
	void create_student();
	void show_student();
	void modify_student();
	char* retadmno();
	char* retstbno();
	char* retstrbno();
	int rettoken();
	void addtoken();
	void resettoken();
	void getstbno(char t[]);
	void getstrbno(char t[]);
	void report();
	int retstate();
	void setres();
	int retres();
	void resetres();
};