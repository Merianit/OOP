#pragma once
#include <fstream>
class Student {
private:
	char* fam;
	char* name;
	char* faculty;
	int group;
public:
	//static int counter;
	Student();
	Student(char* xfam, char* xname, char* xfaculty, int xgroup);
	~Student();
	//Student(Student& ref_student); //конструктор копирования 
	bool operator< (Student &st2);
	bool operator> (Student& st2);
	void operator= (Student& st2);
	int get_group();
	char* get_surname();
	void show_data();
	void get_data();
	void clear();
	void get_data_from_stream(std::fstream& in);
	void send_data_to_stream(std::fstream& out);
};