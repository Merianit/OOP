#pragma once
#include <fstream>
class TICKET;
class FIO
{
friend class TICKET;
friend std::istream& operator>> (std::istream& in, TICKET& ticket);
private:
	char* fam;
	char* name;
	char* patronymic;
public:
	FIO();
	FIO(char* xfam, char* xname, char* xpatronymic);
	~FIO();
};

