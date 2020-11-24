#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int size = 0;
	cin >> size;

	vector<int> inputArray;
	for (int i = 0; i < size; i++) {
		int input = 0;
		cin >> input;
		inputArray.push_back(input);
	}

	vector<long long> multiplicationArray;
	for (int i = 0; i < size; i++) {
		
		long long result = 1;
		for (int j = 0; j < size; j++) {
			if (j != i) {
				result *= inputArray[j];
			}
		}

		multiplicationArray.push_back(result);
	}

	for (int i = 0; i < size; i++) {
		long long output = multiplicationArray[i] % (long long)(pow(10, 9) + 7);
		cout << output << " ";
	}

	return 0;
}
