#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int ARRAY_SIZE = pow(10, 9);

int main() {
	int size = 0;
	cin >> size;

	bool* numbers = new bool[ARRAY_SIZE]();
	for (int i = 0; i < size; i++) {
		int number = 0;
		cin >> number;

		if (number > 0) {
			numbers[number - 1] = true;
		}
	}

	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (!numbers[i]) {
			cout << i + 1;

			break;
		}
	}

	return 0;
}
