#include<iostream>
#include "Date.h"

int main() {
	std::string dayChain;

	std::cout << "Ingrese la fecha YYYY/MM/DD: ";
	std::cin >> dayChain;

	Date date1 = Date(dayChain);

	date1.setYear();
	date1.setMonth();
	date1.setDay();

	date1.toString();
}