#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
	int firstYear, secondYear, numberToSearchFor;
	cin >> firstYear >> secondYear >> numberToSearchFor;

	tm date = {};
	stringstream ss("01-01-" + to_string(firstYear));
	ss >> get_time(&date, "%d-%m-%Y");

	bool found = false;

	while ((date.tm_year + 1900) <= secondYear) {
		const int d1 = date.tm_mday / 10; // First day digit
		const int d2 = date.tm_mday % 10; // Second day digit

		const int month = date.tm_mon + 1;
		const int d3 = month / 10; // First month digit
		const int d4 = month % 10; // Second month digit

		const int year = date.tm_year + 1900;
		const int d5 = year / 1000; // First year digit
		const int d6 = (year / 100) % 10; // Second year digit
		const int d7 = (year / 10) % 10; // Third year digit
		const int d8 = year % 10; // Fourth year digit

		const int weight = d1 * (d2 + d3 + d4 + d5 + d6 + d7 + d8) +
						   d2 * (d3 + d4 + d5 + d6 + d7 + d8) +
						   d3 * (d4 + d5 + d6 + d7 + d8) +
						   d4 * (d5 + d6 + d7 + d8) +
						   d5 * (d6 + d7 + d8) +
						   d6 * (d7 + d8) +
						   d7 * d8;
		
		if (weight == numberToSearchFor) {
			cout << put_time(&date, "%d-%m-%Y") << endl;
			found = true;
		}

		date.tm_mday++;
		mktime(&date);
	}

	if (!found) {
		cout << "No" << endl;
	}

	return 0;
}
