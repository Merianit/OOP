#pragma once
#include "List.h"
#include "student.h"
#include <fstream>

class Database {
private:
	std::fstream file;
	Student* database;
	uint32_t top;
public:
	Database();
	void main_menu();
	void read_file();
	void write_file();
	void show_database();
	void add_entry();
	void find_group();
	void find_surname();
	void alphabet_sort();
	~Database();
};
