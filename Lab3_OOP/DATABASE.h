#pragma once
#include "TICKET.h"
class Database
{
private:
	const int database_length = 1000;
	std::fstream file;
	TICKET* database;
	uint32_t top;
public:
	Database();
	void main_menu();
	void read_file();
	void write_file();
	void show_database();
	void add_entry();
	void find_destination();
	void alphabet_sort();
	~Database();
};
int compare_lines(char* str1, char* str2);

