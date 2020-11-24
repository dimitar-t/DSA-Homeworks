#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int ternarySearch(unsigned long long left, unsigned long long right, unsigned long long target, int counter);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int p, n;
	cin >> p >> n;

	for (int i = 0; i < n; i++) {
		unsigned long long index = 0;
		cin >> index;
		
		printf("%d", ternarySearch(1, pow(3, p), index, 1));
		printf("%s", "\n");
	}

	return 0;
}

int ternarySearch(unsigned long long left, unsigned long long right, unsigned long long target, int counter) {
	while (right >= left) {
		unsigned long long mid1 = left + (right - left) / 3 + 1;
		unsigned long long mid2 = right - (right - left) / 3 - 1;

		if (mid1 == target) {
			return counter;
		}

		if (mid2 == target) {
			return counter;
		}

		if (mid1 == mid2) {
			return ++counter;
		}


		if (target < mid1) {
			right = mid1 - 1;
			counter++;
		}
		else if (target > mid2) {
			left = mid2 + 1;
			counter++;
		}
		else {
			return counter;
		}
	}

	return -1;
}