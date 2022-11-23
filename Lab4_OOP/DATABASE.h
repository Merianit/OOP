#pragma once
#include "COMMON.h"
#include "STORAGE.h"
#include "STOCK.h"

enum classes { storage, stock };
class Database
{
private:
	const int database_length = 100;
	std::fstream file;
	STORAGE* database_storage;
	STOCK* database_stock;
	uint32_t top;
	classes type_flag; 
public:
	Database(classes);
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

