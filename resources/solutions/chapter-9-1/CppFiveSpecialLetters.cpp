#include <iostream>
#include <string>

using namespace std;

int main()
{
	int firstNumber, secondNumber;
	cin >> firstNumber >> secondNumber;

	string pattern = "abcde";
	string result;

	for (int i1 = 0; i1 < 5; i1++) {
		for (int i2 = 0; i2 < 5; i2++) {
			for (int i3 = 0; i3 < 5; i3++) {
				for (int i4 = 0; i4 < 5; i4++) {
					for (int i5 = 0; i5 < 5; i5++) {
						string word;
						word += pattern[i1];

						if (word.find(pattern[i2]) == string::npos) {
							word += pattern[i2];
						}
						if (word.find(pattern[i3]) == string::npos) {
							word += pattern[i3];
						}
						if (word.find(pattern[i4]) == string::npos) {
							word += pattern[i4];
						}
						if (word.find(pattern[i5]) == string::npos) {
							word += pattern[i5];
						}

						int weight = 0;
						for (int i = 0; i < word.length(); i++) {
							int multiplier = 0;
							if (word[i] == 'a') {
								multiplier = 5;
							}
							if (word[i] == 'b') {
								multiplier = -12;
							}
							if (word[i] == 'c') {
								multiplier = 47;
							}
							if (word[i] == 'd') {
								multiplier = 7;
							}
							if (word[i] == 'e') {
								multiplier = -32;
							}
							weight += multiplier * (i + 1);
						}

						if (firstNumber <= weight && weight <= secondNumber) {
							string fullWord;
							fullWord += pattern[i1];
							fullWord += pattern[i2];
							fullWord += pattern[i3];
							fullWord += pattern[i4];
							fullWord += pattern[i5];
							result += fullWord + " ";
						}
					}
				}
			}
		}
	}

	if (result.empty()) {
		cout << "No" << endl;
	} else {
		cout << result.substr(0, result.length() - 1) << endl;
	}
}
