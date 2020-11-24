#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, targetProfit;
	cin >> n >> targetProfit;

	int sum = 0;
	queue<int> profits;
	for (int i = 0; i < n; i++) {
		int profit = 0;
		cin >> profit;
		profits.push(profit);

		sum += profit;
	}

	if (sum < targetProfit) {
		printf("%d", -1);
	}
	else {
		while (true) {
			if (sum > targetProfit) {
				sum -= profits.front();
				profits.pop();
			}
			else {
				int count = 1;

				if (sum - profits.front() > 0) {
					sum -= profits.front();
					profits.pop();

					count++;
				}
				else {
					printf("%d", count);

					break;
				}
			}
		}
	}

	return 0;
}