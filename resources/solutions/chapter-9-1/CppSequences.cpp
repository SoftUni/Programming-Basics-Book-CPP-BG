#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int tribonacciFirst, tribonacciSecond, tribonacciThird;
	cin >> tribonacciFirst >> tribonacciSecond >> tribonacciThird;

	int spiralCurrent, spiralStep;
	cin >> spiralCurrent >> spiralStep;

	// Tribonacci
	vector<int> tribonacciNumbers;
	tribonacciNumbers.push_back(tribonacciFirst);
	tribonacciNumbers.push_back(tribonacciSecond);
	tribonacciNumbers.push_back(tribonacciThird);

	int tribonacciCurrent = tribonacciThird;
	while (tribonacciCurrent < 1000000) {
		tribonacciCurrent = tribonacciFirst +
			tribonacciSecond +
			tribonacciThird;

		tribonacciNumbers.push_back(tribonacciCurrent);

		tribonacciFirst = tribonacciSecond;
		tribonacciSecond = tribonacciThird;
		tribonacciThird = tribonacciCurrent;
	}

	// Spiral
	vector<int> spiralNumbers;
	spiralNumbers.push_back(spiralCurrent);
	int spiralCount = 0;
	int spiralStepMul = 1;
	while (spiralCurrent < 1000000) {
		spiralCurrent += spiralStep * spiralStepMul;
		spiralNumbers.push_back(spiralCurrent);
		spiralCount++;
		if (spiralCount % 2 == 0) {
			spiralStepMul += 1;
		}
	}

	// Find answer
	bool found = false;
	for (int tribonacciNumber : tribonacciNumbers) {
		for (int spiralNumber : spiralNumbers) {
			if (tribonacciNumber == spiralNumber && tribonacciNumber <= 1000000) {
				cout << tribonacciNumber << endl;
				found = true;
				break;
			}
		}

		if (found) {
			break;
		}
	}

	if (!found) {
		cout << "No" << endl;
	}

	/* while (tribonacciCurrent <= 1000000 && spiralCurrent <= 1000000) {
		if (tribonacciCurrent == spiralCurrent) {
			cout << "TODO: Print and stop execution" << endl;
		}
		else if (tribonacciCurrent < spiralCurrent) {
			cout << "TODO: Generate next Tribonacci number" << endl;
		}
		else {
			cout << "TODO: Generate next Spiral number" << endl;
		}
	} */

	return 0;
}
