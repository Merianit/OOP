#pragma once
#include "COMMON.h"
// ticket
class STORAGE : public COMMON
{
	friend std::istream& operator>> (std::istream& in, STORAGE& ticket);
private:
	char* departure_point;
	char* arrival_point;
public:
	STORAGE();
	STORAGE& operator= (STORAGE& st2);
	char* get_destination();
	bool operator< (STORAGE& tc2);
	bool operator> (STORAGE& tc2);
	void show_data();
	void get_data_from_stream(std::fstream& in);
	void send_data_to_stream(std::fstream& out);
	~STORAGE();
};

