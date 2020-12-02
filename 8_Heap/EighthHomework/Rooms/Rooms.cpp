#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	auto compare = [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; };
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> exercises(compare);

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;

		if (start != end) {
			exercises.push(make_pair(start, end));
		}
	}

	if (exercises.empty()) {
		printf("%d", 0);
	}
	else {
		vector<pair<int, int>> busyRooms;

		while (!exercises.empty()) {
			pair<int, int> current = exercises.top();
			exercises.pop();

			bool isFree = false;
			for (size_t i = 0; i < busyRooms.size(); i++) {
				if (busyRooms[i].second <= current.first) {
					isFree = true;
					busyRooms[i].second = current.second;

					break;
				}
			}

			if (!isFree) {
				busyRooms.push_back(current);
			}
		}

		printf("%d", (int)busyRooms.size());
	}

	return 0;
}