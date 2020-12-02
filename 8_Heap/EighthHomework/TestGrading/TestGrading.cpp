#include <iostream>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

struct compareAll {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.first > b.first;
	}
};

struct compareEligible {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	priority_queue<pair<int, int>, vector<pair<int, int>>, compareAll> submissions;
	
	for (int i = 0; i < n; i++) {
		int time, lines;
		cin >> time >> lines;

		submissions.push(make_pair(time, lines));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, compareEligible> eligible;
	eligible.push(submissions.top());
	submissions.pop();

	long long timePassed = eligible.top().first;
	double totalWaitingTime = 0;

	while (!eligible.empty()) {
		double currentWaitingTime = 0;
		pair<int, int> current = eligible.top();
		eligible.pop();

		// determine who is waiting for who
		if (timePassed - current.first > 0) {
			currentWaitingTime += (timePassed - current.first);
		}
		else {
			timePassed += (current.first - timePassed);
		}

		// add the corresponding times
		timePassed += current.second;
		currentWaitingTime += current.second;

		// add the eligible submissions
		while (!submissions.empty()) {
			pair<int, int> toAdd = submissions.top();

			if (timePassed >= toAdd.first) {
				eligible.push(toAdd);
				submissions.pop();
			}
			else {
				// no submissions at this time
				if (eligible.empty()) {
					eligible.push(toAdd);
					submissions.pop();
				}

				break;
			}
		}

		totalWaitingTime += currentWaitingTime;
	}

	cout << fixed << setprecision(0) << floor(totalWaitingTime / n);

	return 0;
}