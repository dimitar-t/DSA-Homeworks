#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long MAX_UNIQUE_BOUND = pow(10, 9);

int main() {
	long long lowerBound = 0;
	long long upperBound = 0;
	cin >> lowerBound >> upperBound;

	if (upperBound > MAX_UNIQUE_BOUND) {
		upperBound = MAX_UNIQUE_BOUND;
	}

	int count = 0;
	for (long long i = lowerBound; i <= upperBound; i++) {
		long long num = i;
		vector<int> digits;

		bool hasRepeating = false;
		while (num != 0) {
			if (find(digits.begin(), digits.end(), num % 10) == digits.end()) {
				digits.push_back(num % 10);
				num /= 10;
			}
			else {
				hasRepeating = true;
				break;
			}
		}

		if (!hasRepeating) {
			count++;
		}
	}

	cout << count;

	return 0;
}