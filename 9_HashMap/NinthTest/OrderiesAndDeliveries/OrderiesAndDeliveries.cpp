#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	unordered_map<int, int> carts;

	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;

		if (carts.find(id) == carts.end()) {
			carts.insert({ id, 0 });
		}

		carts[id]++;

		if (carts[id] == 10) {
			carts[id] = 0;
		}
	}

	int fullCarts = 0;
	int productsCount = 0;

	for (auto it = carts.begin(); it != carts.end(); it++) {
		if (it->second != 0) {
			fullCarts++;
			productsCount += it->second;
		}
	}

	printf("%d %d", fullCarts, productsCount);

	return 0;
}