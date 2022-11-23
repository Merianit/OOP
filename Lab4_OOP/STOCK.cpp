#include "STOCK.h"
#include <iomanip>

STOCK::STOCK()
{
	wagon_number = 0;
	seat_number = 0;
	ticket_price = 0.0;
}
void STOCK::temp_init() {
	passenger.name = new char[160];
	passenger.fam = new char[160];
	passenger.patronymic = new char[160];
}

bool STOCK::operator< (STOCK& st2)
{
	char* str1 = passenger.patronymic;
	char* str2 = st2.passenger.patronymic;

	int len = ((int)strlen(str1) < (int)strlen(str2)) ? (int)strlen(str1) : (int)strlen(str2);
	for (int i = 0; i < len; i++) {
		if (*(str1 + i) > *(str2 + i))
			return 1;
		if (*(str1 + i) < *(str2 + i))
			return 0;
	}
	return 0;
}

bool STOCK::operator> (STOCK& st2)
{
	char* str1 = passenger.patronymic;
	char* str2 = st2.passenger.patronymic;

	int len = ((int)strlen(str1) < (int)strlen(str2)) ? (int)strlen(str1) : (int)strlen(str2);
	for (int i = 0; i < len; i++) {
		if (*(str1 + i) > *(str2 + i))
			return 0;
		if (*(str1 + i) < *(str2 + i))
			return 1;
	}
	return 0;
	
}

void STOCK::show_data() const
{
	std::cout << passenger.name << std::setw(10) << passenger.fam
		<< std::setw(20) << passenger.patronymic << std::setw(10) << wagon_number
		<< std::setw(10) << seat_number << std::setw(10) << ticket_price << std::endl;
}

void STOCK::get_data_from_stream(std::fstream& in) {
	in >> passenger.name >> passenger.fam >> passenger.patronymic >> wagon_number >> seat_number >> ticket_price;
}

void STOCK::send_data_to_stream(std::fstream& out) {
	out << passenger.name << " " << passenger.fam << " " << passenger.patronymic << " " << wagon_number << " " << seat_number << " " << ticket_price << std::endl;
}

STOCK& STOCK::operator= (STOCK& st2)
{
	strcpy_s(passenger.name, 160, st2.passenger.name);
	strcpy_s(passenger.fam, 160, st2.passenger.fam);
	strcpy_s(passenger.patronymic, 160, st2.passenger.patronymic);
	ticket_price = st2.ticket_price;
	wagon_number = st2.wagon_number;
	seat_number = st2.seat_number;
	return *this;
}



// Перегрузка с помощью дружественной функции
std::istream& operator>> (std::istream& in, STOCK& ticket)
{
	std::cout << "Please, enter the data..." << std::endl;
	in >> ticket.passenger.name >> ticket.passenger.fam >> ticket.passenger.patronymic >> ticket.wagon_number >> ticket.seat_number;
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