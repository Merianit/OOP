#include "COMMON.h"

bool COMMON::is_empty() {
	if (ticket_price == 0.0)
		return true;
	return false;
}

void COMMON::clear() {
	ticket_price = 0.0;
}