#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> readArray(int size) {
	vector<int> array;
	for (int i = 0; i < size; i++) {
		int number;
		cin >> number;

		if (find(array.begin(), array.end(), number) == array.end()) {
			array.push_back(number);
		}
	}

	return array;
}

int calculateSum(vector<int> biggerArray, vector<int> smallerArray) {
	int sum = 0;
	for (int i = 0; i < smallerArray.size(); i++) {
		if (find(biggerArray.begin(), biggerArray.end(), smallerArray[i]) != biggerArray.end()) {
			sum += smallerArray[i];
		}
	}

	return sum;
}

int main() {
	int firstSize;
	cin >> firstSize;
	vector<int> firstArray = readArray(firstSize);

	int secondSize;
	cin >> secondSize;
	vector<int> secondArray = readArray(secondSize);

	int sum = 0;
	if (firstSize >= secondSize) {
		sum = calculateSum(secondArray, firstArray);
	}
	else {
		sum = calculateSum(firstArray, secondArray);
	}

	cout << sum;

	return 0;
}
