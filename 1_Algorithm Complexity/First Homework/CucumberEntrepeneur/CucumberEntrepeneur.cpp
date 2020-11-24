#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int days = 0;
	cin >> days;

	vector<int> prices = vector<int>();
	for (int i = 0; i < days; i++) {
		int price = 0;
		cin >> price;
		prices.push_back(price);
	}

	int revenue = 0;
	for (int i = 0; i < prices.size() - 1; i++) {
		if (prices[i] < prices[i + 1]) {
			revenue += prices[i + 1] - prices[i];
		}
	}

	cout << revenue;

	return 0;
}