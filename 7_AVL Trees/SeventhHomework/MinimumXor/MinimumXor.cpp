#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <limits>

using namespace std;

int minXor(set<int>& nums, int newNum);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	set<int> nums { 0 };
	int currentMin = numeric_limits<int>::max();

	for (int i = 0; i < q; i++) {
		int input;
		cin >> input;

		nums.insert(input);

		int result = minXor(nums, input);

		if (result < currentMin) {
			currentMin = result;
		}

		printf("%d\n", currentMin);
	}

	return 0;
}

int minXor(set<int>& nums, int newNum) {
	set<int>::iterator current = nums.lower_bound(newNum);
	set<int>::iterator bigger = nums.upper_bound(newNum);

	int firstResult;
	int secondResult;

	if (current != nums.begin()) {
		int smaller = *prev(current);
		firstResult = newNum ^ smaller;
	}

	if (bigger != nums.end()) {
		secondResult = newNum ^ *bigger;
	}

	return firstResult < secondResult ? firstResult : secondResult;
}