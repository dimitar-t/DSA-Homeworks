#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d;
	cin >> n >> d;

	long long sum = 0;
	queue<long long> subArray;
	deque<long long> minValues;
	if (d > 0) {
		for (int i = 0; i < n; i++) {
			long long input;
			cin >> input;

			if (subArray.size() == d) {
				sum += minValues.front();

				if (subArray.front() == minValues.front()) {
					minValues.pop_front();
				}

				subArray.pop();
			}

			subArray.push(input);

			while (!minValues.empty()) {
				if (minValues.back() < input) {
					break;
				}

				minValues.pop_back();
			}

			minValues.push_back(input);
		}
	}

	sum += minValues.front();

	cout << sum;

	return 0;
}