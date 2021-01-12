#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> boolArray;

	for (int i = 0; i < n; i++) {
		bool input;
		cin >> input;
		boolArray.push_back(input ? 1 : -1);
	}

	unordered_map<int, int> indexes;
	indexes[0] = -1;

	int maxCount = 0;
	int endingIndex = -1;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += boolArray[i];

		if (indexes.find(sum) != indexes.end()) {
			if (maxCount < i - indexes[sum]) {
				maxCount = i - indexes[sum];
				endingIndex = i;
			}
		}
		else {
			indexes[sum] = i;
		}
	}

	cout << maxCount;

	return 0;
}