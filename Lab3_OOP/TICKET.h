#pragma once
#include "FIO.h"
#include <iostream>
class TICKET
{
friend std::istream& operator>> (std::istream& in, TICKET &ticket);
private:
	FIO passenger;
	char* departure_point;
	char* arrival_point;
	double ticket_price;
public:
	TICKET();
    TICKET& operator= (TICKET& st2);
	bool operator< (TICKET& tc2);
	bool operator> (TICKET& tc2);
	void get_data_from_stream(std::fstream& in);
	void send_data_to_stream(std::fstream& out);
	void clear();
	bool is_empty();
	void show_data();
	char* get_destination();
	~TICKET();
};
std::istream& operator>> (std::istream& in, TICKET &ticket);
