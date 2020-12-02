#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<int> prices;

	for (int i = 0; i < n; i++) {
		int bid;
		cin >> bid;

		if (bid != -1) {
			prices.push(bid);
		}
		else {
			if (!prices.empty()) {
				cout << prices.top() << " ";
				prices.pop();
			}
		}
	}

	return 0;
}