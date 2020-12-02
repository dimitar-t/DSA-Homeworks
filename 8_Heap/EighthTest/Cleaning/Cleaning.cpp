#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) const {
		return a.second > b.second;
	}
};

int main() {
	int n, q;
	cin >> n >> q;

	set<pair<int, int>, compare> intervals;

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;

		intervals.insert(make_pair(start, end));
	}

	for (int i = 0; i < q; i++) {
		int timestamp;
		cin >> timestamp;

		auto entry = intervals.lower_bound({ numeric_limits<int>::min(), timestamp });
		
		int count = 0;
		while (entry != intervals.end()) {
			pair<int, int> current = *entry;

			if (timestamp >= current.first && timestamp <= current.second) {
				count++;
				entry = next(entry);
			}
			else {
				break;
			}
		}

		if (entry == intervals.begin()) {
			pair<int, int> current = *entry;

			if (current.first >= timestamp && current.second <= timestamp) {
				count++;
			}
		}

		cout << count << " ";
	}

	return 0;
}