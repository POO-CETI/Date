#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	string dayChain;
	char repit;

	cout << "Ingrese la fecha YYYY/MM/DD: ";
	cin >> dayChain;

	Date date1 = Date(dayChain);
	//++date1;
	date1.toString();
	do {
		cout << "\nQuieres incrementar un dia (s/n)? ";
		scanf("%s", &repit);

		if (repit == 's' || repit == 'S')
			++date1;

		date1.toString();
	} while(repit == 's' || repit == 'S');
}