#include "FIO.h"
FIO::FIO()
{
	fam = new char[160];
	name = new char[160];
	patronymic = new char[160];
}

FIO::FIO(char* xfam, char* xname, char* xpatronymic)
{
	fam = new char[160];
	name = new char[160];
	patronymic = new char[160];
	strcpy_s(fam, 160, xfam);
	strcpy_s(name, 160, xname);
	strcpy_s(patronymic, 160, xpatronymic);
}

FIO::~FIO() {
	delete[] fam;
	delete[] name;
	delete[] patronymic;
	fam = nullptr;
	name = nullptr;
	patronymic = nullptr;
}

