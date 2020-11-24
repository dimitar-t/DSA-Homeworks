#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int findRightmost(vector<int>& arr, int start, int end, int x);
int findMinimumCountOfNumbers(vector<int>& numbers, int maxSum, int maxNum);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	vector<int> numbers;
	for (int i = 0; i < n; i++) {
		int number = 0;
		cin >> number;
		numbers.push_back(number);
	}

	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < q; i++) {
		int maxSum, maxNum;
		cin >> maxSum >> maxNum;

		int count = findMinimumCountOfNumbers(numbers, maxSum, maxNum);

		printf("%d", count);
		printf("%s", "\n");
	}

	return 0;
}

int findRightmost(vector<int>& arr, int start, int end, int x) {
	while (end > start) {
		int mid = (start + end) / 2;

		if (arr[mid] > x) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}

	return end - 1;
}

int findMinimumCountOfNumbers(vector<int>& numbers, int maxSum, int maxNum) {
	int currentSum = 0;
	int counter = 0;
	int end = findRightmost(numbers, 0, numbers.size(), maxNum);

	for (int i = end; i >= 0; i--) {
		if (currentSum + numbers[i] <= maxSum) {
			currentSum += numbers[i];
			counter++;
		}
		else {
			break;
		}
	}

	return counter;
}