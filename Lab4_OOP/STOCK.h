#pragma once
#include "COMMON.h"
#include "DATE.h"
// ticket1
// Наследует:
// FIO passenger;
// double ticket_price;
class STOCK : public COMMON
{
friend std::istream& operator>> (std::istream& in, STOCK& ticket);
private:
	int wagon_number;
	int seat_number;
	DATE travel;
public:
	STOCK();
	STOCK& operator= (STOCK& st2);
	void show_data() const;
	void temp_init();
	void get_data_from_stream(std::fstream& in);
	void send_data_to_stream(std::fstream& out);
	bool operator< (STOCK& tc2);
	bool operator> (STOCK& tc2);
	//~STOCK();
};

