#pragma once
#include <fstream>
class TICKET;
class FIO
{
friend class TICKET;
friend std::istream& operator>> (std::istream& in, TICKET& ticket);
public:
	char* fam;
	char* name;
	char* patronymic;

	FIO();
	FIO(char* xfam, char* xname, char* xpatronymic);
	~FIO();
};

