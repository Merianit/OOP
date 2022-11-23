#include "STORAGE.h"
#include <iomanip>
STORAGE::STORAGE()
{
	departure_point = new char[160];
	arrival_point = new char[160];
	ticket_price = 0.0;
}

STORAGE::~STORAGE() {
	delete[] departure_point;
	delete[] arrival_point;
	departure_point = nullptr;
	arrival_point = nullptr;
}

bool STORAGE::operator< (STORAGE& tc2)
{
	char* str1 = departure_point;
	char* str2 = tc2.departure_point;

	int len = ((int)strlen(str1) < (int)strlen(str2)) ? (int)strlen(str1) : (int)strlen(str2);
	for (int i = 0; i < len; i++) {
		if (*(str1 + i) > *(str2 + i))
			return 1;
		if (*(str1 + i) < *(str2 + i))
			return 0;
	}
	return 0;
}

bool STORAGE::operator> (STORAGE& tc2)
{
	char* str1 = departure_point;
	char* str2 = tc2.departure_point;

	int len = ((int)strlen(str1) < (int)strlen(str2)) ? (int)strlen(str1) : (int)strlen(str2);
	for (int i = 0; i < len; i++) {
		if (*(str1 + i) > *(str2 + i))
			return 0;
		if (*(str1 + i) < *(str2 + i))
			return 1;
	}
	return 0;
}

void STORAGE::show_data()
{
	std::cout << passenger.name << std::setw(10) << passenger.fam
		<< std::setw(20) << passenger.patronymic << std::setw(10) << departure_point
		<< std::setw(10) << arrival_point << std::setw(10) << ticket_price << std::endl;
}

void STORAGE::get_data_from_stream(std::fstream& in) {
	in >> passenger.name >> passenger.fam >> passenger.patronymic >> departure_point >> arrival_point >> ticket_price;
}

void STORAGE::send_data_to_stream(std::fstream& out) {
	out << passenger.name << " " << passenger.fam << " " << passenger.patronymic << " " << departure_point << " " << arrival_point << " " << ticket_price << std::endl;
}

STORAGE& STORAGE::operator= (STORAGE& st2)
{
	strcpy_s(passenger.name, 160, st2.passenger.name);
	strcpy_s(passenger.fam, 160, st2.passenger.fam);
	strcpy_s(passenger.patronymic, 160, st2.passenger.patronymic);
	strcpy_s(departure_point, 160, st2.departure_point);
	strcpy_s(arrival_point, 160, st2.arrival_point);
	ticket_price = st2.ticket_price;
	return *this;
}

char* STORAGE::get_destination() {
	return arrival_point;
}


// Перегрузка с помощью дружественной функции
std::istream& operator>> (std::istream& in, STORAGE& ticket)
{
	std::cout << "Please, enter the data..." << std::endl;
	in >> ticket.passenger.name >> ticket.passenger.fam >> ticket.passenger.patronymic >> ticket.departure_point >> ticket.arrival_point;
	std::cin >> ticket.ticket_price;
	while (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Error, please enter correct value" << std::endl;
		std::cin >> ticket.ticket_price;
	}
	return in;
}