#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int findPosition(vector<int> vector, int number) {
	for (int i = vector.size() - 1; i >= 0; i--) {
		if (vector[i] <= number) {
			return i + 1;
		}
	}

	return 0;
}

void insertNumber(vector<int>& vector, int number) {
	if (vector.size() != 0) {
		int position = findPosition(vector, number);
		vector.resize(vector.size() + 1);

		for (int i = vector.size() - 1; i > position; i--) {
			swap(vector[i - 1], vector[i]);
		}

		vector[position] = number;
	}
	else {
		vector.push_back(number);
	}
}

double findMedian(vector<int> vector) {
	if (vector.size() % 2 != 0) {
		return vector[vector.size() / 2];
	}

	return (vector[vector.size() / 2] + vector[(vector.size() / 2) - 1]) / 2.0;
}

int main() {
	int capacity;
	cin >> capacity;

	vector<int> numbers;
	for (int i = 0; i < capacity; i++) {
		int number;
		cin >> number;

		insertNumber(numbers, number);

		cout << findMedian(numbers) << endl;
	}

	return 0;
}
