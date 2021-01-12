#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	unordered_set<int> weights;

	for (int i = 0; i < n; i++) {
		int weight;
		cin >> weight;
		weights.insert(weight);
	}

	for (auto i = weights.begin(); i != weights.end(); i++) {
		for (auto j = next(i); j != weights.end(); j++) {
			if (weights.find(*i + *j) != weights.end()) {
				printf("%s", "true");

				return 0;
			}
		}
	}

	printf("%s", "false");

	return 0;
}
