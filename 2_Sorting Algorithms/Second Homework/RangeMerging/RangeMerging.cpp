#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Range {
	int Start;
	int End;
};

bool compareRanges(Range bigger, Range smaller);

void mergeSort(vector<Range>& arr, int l, int r);

void merge(vector<Range>& arr, int l, int mid, int r);

void mergeRanges(vector<Range>& arr);

int main() {
	int n;
	cin >> n;

	vector<Range> ranges;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;

		Range range = { start, end };
		ranges.push_back(range);
	}
	
	mergeSort(ranges, 0, ranges.size() - 1);
	
	mergeRanges(ranges);

	for (int i = 0; i < ranges.size(); i++) {
		cout << ranges[i].Start << " " << ranges[i].End << endl;
	}

	return 0;
}

bool compareRanges(Range smaller, Range bigger) {
	if (smaller.Start < bigger.Start) {
		return true;
	}

	if (smaller.Start == bigger.Start) {
		if (smaller.End <= bigger.End) {
			return true;
		}
	}

	return false;
}

void mergeSort(vector<Range>& arr, int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;

		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);

		merge(arr, l, mid, r);
	}
}

void merge(vector<Range>& arr, int l, int mid, int r) {
	int n1 = mid - l + 1;
	int n2 = r - mid;

	vector<Range> left;
	for (int i = 0; i < n1; i++) {
		left.push_back(arr[l + i]);
	}

	vector<Range> right;
	for (int i = 0; i < n2; i++) {
		right.push_back(arr[mid + 1 + i]);
	}

	int i = 0;
	int j = 0;
	int k = l;

	while (i < n1 && j < n2) {
		if (compareRanges(left[i], right[j])) {
			arr[k] = left[i];

			i++;
		}
		else {
			arr[k] = right[j];

			j++;
		}

		k++;
	}

	while (i < n1) {
		arr[k] = left[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = right[j];
		j++;
		k++;
	}
}

void mergeRanges(vector<Range>& arr) {
	for (int i = 0; i < arr.size() - 1; i++) {		
		if (arr[i].End >= arr[i + 1].Start) {
			int mergedEnd = arr[i].End > arr[i + 1].End ? arr[i].End : arr[i + 1].End;
			Range merged = { arr[i].Start, mergedEnd };
			arr[i] = merged;

			arr.erase(arr.begin() + i + 1);
			i--;
		}
	}
}