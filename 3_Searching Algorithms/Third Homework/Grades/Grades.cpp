#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> readGrades(int size);

int findLeftmost(vector<int>& arr, int start, int end, int x);
int findRightmost(vector<int>& arr, int start, int end, int x);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int size, q;
	cin >> size >> q;

	vector<int> grades = readGrades(size);
	sort(grades.begin(), grades.end());

	for (int i = 0; i < q; i++) {
		int first, second;
		cin >> first >> second;

		if (first > second) {
			printf("%s", "0\n");
		}
		else {
			int lowerIndex = findLeftmost(grades, 0, grades.size(), first);
			int higherIndex = findRightmost(grades, 0, grades.size(), second);

			printf("%d", higherIndex - lowerIndex + 1);
			printf("%s", "\n");
		}
	}

	return 0;
}

vector<int> readGrades(int size) {
	vector<int> grades;
	for (int i = 0; i < size; i++) {
		int grade = 0;
		cin >> grade;
		grades.push_back(grade);
	}

	return grades;
}

int findLeftmost(vector<int>& arr, int start, int end, int x) {
	while (end > start) {
		int mid = (start + end) / 2;

		if (arr[mid] >= x) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}

	return start;
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