#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;

	set<int> masks;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		for (int submask = input; ; submask = (submask - 1) & input) {
			masks.insert(submask);

			if (submask == 0) {
				break;
			}
		}
	}

	cout << masks.size() << endl;

	return 0;
}