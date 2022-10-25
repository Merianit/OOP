#pragma once
#include "student.h"
#include "List.h"
#include "cstring"
#include "iostream"
#include "iomanip"
#include <fstream>

//Реализация класса Student
Student::Student() 
{
	fam = new char[160];
	name = new char[160];
	faculty = new char[160];
	group = 0;
	//counter++;
}

Student::Student(char* xfam, char* xname, char* xfaculty, int xgroup)
{
	fam = new char[160];
	name = new char[160];
	faculty = new char[160];
	group = 0;
	//counter++;
	strcpy_s(fam, 160, xfam);
	strcpy_s(name, 160 , xname);
	strcpy_s(faculty, 160, xfaculty);
	group = xgroup;
}

Student::~Student() 
{
	delete[] fam;
	delete[] name;
	delete[] faculty;
	group = 0;
	//counter--;
}

bool Student::operator< (Student &st2)
{
	char* str1 = name;
	char* str2 = st2.name;

	int len = ((int)strlen(str1) < (int)strlen(str2)) ? (int)strlen(str1) : (int)strlen(str2);
	for (int i = 0; i < len; i++) {
		if (*(str1 + i) > *(str2 + i))
			return 1;
		if (*(str1 + i) < *(str2 + i))
			return 0;
	}
	return 0;
}

bool Student::operator> (Student& st2)
{
	char* str1 = name;
	char* str2 = st2.name;

	int len = ((int)strlen(str1) < (int)strlen(str2)) ? (int)strlen(str1) : (int)strlen(str2);
	for (int i = 0; i < len; i++) {
		if (*(str1 + i) > *(str2 + i))
			return 0;
		if (*(str1 + i) < *(str2 + i))
			return 1;
	}
	return 0;
}

void Student::show_data()
{
	std::cout << std::setw(10) << name << std::setw(20) << fam
		<< std::setw(20) << faculty << std::setw(20) << group << std::endl;
}

void Student::get_data() 
{
	std::cout << "Please, enter the data..." << std::endl;
	std::cin >> name >> fam >> faculty;
	std::cin >> group;
	while (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Error, please enter correct value" << std::endl;
		std::cin >> group;
	}
}

void Student::get_data_from_stream(std::fstream& in){
	in >> name >> fam >> faculty >> group;
}

void Student::send_data_to_stream(std::fstream& out) {
	out << name << " " << fam <<" "<< faculty<<" "<< group << std::endl;
}

void Student::operator = (Student& st2)
{
	strcpy_s(name, 160, st2.name);
	strcpy_s(fam, 160, st2.fam);
	strcpy_s(faculty, 160, st2.faculty);
	group = st2.group;
}

int Student::get_group() {
	return group;
}

void Student::clear() {
	group = 0;
}

char* Student::get_surname() {
	return fam;
}