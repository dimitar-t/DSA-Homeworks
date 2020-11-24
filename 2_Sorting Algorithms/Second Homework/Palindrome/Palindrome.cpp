#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int ARRAY_SIZE = 128;

int* getLettersCount(string word) {
	int* lettersCount = new int[ARRAY_SIZE]();

	for (int i = 0; i < word.length(); i++) {
		lettersCount[word[i]]++;
	}

	return lettersCount;
}

bool isPalindrome(string word) {
	int* lettersCount = getLettersCount(word);

	int oddCounter = 0;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (lettersCount[i] % 2 != 0) {
			oddCounter++;

			if (oddCounter > 1) {
				delete[] lettersCount;

				return false;
			}
		}
	}

	delete[] lettersCount;

	return true;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;

		if (isPalindrome(word)) {
			cout << "TRUE" << endl;
		}
		else {
			cout << "FALSE" << endl;
		}
	}

	return 0;
}
