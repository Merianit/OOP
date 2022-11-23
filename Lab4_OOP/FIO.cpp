#include "FIO.h"
FIO::FIO()
{
	fam = new char[160];
	name = new char[160];
	patronymic = new char[160];
}

FIO::FIO(char* xfam, char* xname, char* xpatronymic)
{
	strcpy_s(fam, strlen(fam), xfam);
	strcpy_s(name, strlen(name), xname);
	strcpy_s(patronymic, strlen(patronymic), xpatronymic);
}

FIO::~FIO() {
	delete[] fam;
	delete[] name;
	delete[] patronymic;
	fam = nullptr;
	name = nullptr;
	patronymic = nullptr;
}

