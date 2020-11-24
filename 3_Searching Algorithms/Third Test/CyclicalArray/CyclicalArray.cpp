#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>& arr, int start, int end, int target);

int main() {
	int n;
	cin >> n;

	vector<int> numbers;
	int min = numeric_limits<int>::max();
	int minIndex = -1;
	for (int i = 0; i < n; i++) {
		int number = 0;
		cin >> number;
		numbers.push_back(number);

		if (number < min) {
			min = number;
			minIndex = i;
		}
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int target = 0;
		cin >> target;

		int result = binarySearch(numbers, minIndex, numbers.size() - 1, target);

		if (result != -1) {
			cout << result << endl;
		}
		else {
			cout << binarySearch(numbers, 0, minIndex - 1, target) << endl;
		}
	}

	return 0;
}

int binarySearch(vector<int>& arr, int start, int end, int target) {
	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == target) {
			return mid;
		}

		if (arr[mid] < target) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	return -1;
}