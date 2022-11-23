#pragma once
#include "FIO.h"
#include <iostream>
class COMMON
{
	
protected:
	FIO passenger;
	double ticket_price;
public:
	//COMMON();
	//virtual COMMON& operator= (COMMON& st2);
	//virtual bool operator< (COMMON& tc2);
	//virtual bool operator> (COMMON& tc2);
	//virtual void get_data_from_stream(std::fstream& in);
	//virtual void send_data_to_stream(std::fstream& out);
	void clear();
	bool is_empty();
	//virtual void show_data();

	//~COMMON();
};
std::istream& operator>> (std::istream& in, TICKET& ticket);


