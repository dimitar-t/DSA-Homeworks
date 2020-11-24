#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int ARRAY_SIZE = 200001;

int main() {
	int n;
	cin >> n;

	int* counts = new int[ARRAY_SIZE]();
	for (int i = 0; i < n; i++) {
		int prize;
		cin >> prize;
		
		counts[prize]++;
	}

	for (int i = ARRAY_SIZE; i >= 0; i--) {
		if (counts[i] > 0) {
			for (int j = 0; j < counts[i]; j++) {
				cout << i << " ";
			}
		}
	}

	return 0;
}
