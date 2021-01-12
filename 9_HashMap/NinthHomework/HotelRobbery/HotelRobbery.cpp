#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int keysToBuy = 0;
	unordered_map<int, priority_queue<int, vector<int>, greater<int>>> keysFound;

	for (int i = 0; i < n - 1; i++) {
		int foundKey;
		cin >> foundKey;

		if (keysFound.find(foundKey) == keysFound.end()) {
			keysFound.insert({ foundKey, priority_queue<int, vector<int>, greater<int>>() });
		}

		keysFound[foundKey].push(i);
	}

	for (int i = 0; i < n - 1; i++) {
		int neededKey;
		cin >> neededKey;

		auto key = keysFound.find(neededKey);
		bool roomUnlocked = false;

		if (key != keysFound.end()) {
			int lowestIndex = keysFound[neededKey].top();

			if (lowestIndex <= i) {
				keysFound[neededKey].pop();

				if (keysFound[neededKey].empty()) {
					keysFound.erase(key);
				}

				roomUnlocked = true;
			}
		}

		if (!roomUnlocked) {
			keysToBuy++;
		}
	}

	printf("%d", keysToBuy);

	return 0;
}
