#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int ARRAY_SIZE = 50001;

int main() {
	int n;
	cin >> n;

	int* counts = new int[ARRAY_SIZE]();
	for (int i = 0; i < n; i++) {
		int folder = 0;
		cin >> folder;

		counts[folder]++;
	}

	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (counts[i] > 0) {
			cout << i << " ";
		}
	}

	return 0;
}
