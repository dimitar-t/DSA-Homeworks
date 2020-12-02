#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

void balanceHeaps(priority_queue<double>& maxHeap, priority_queue<double, vector<double>, greater<double>>& minHeap);
double getMedian(priority_queue<double>& maxHeap, priority_queue<double, vector<double>, greater<double>>& minHeap);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	priority_queue<double> maxHeap;
	priority_queue<double, vector<double>, greater<double>> minHeap;
	double currentMedian = 0;

	for (int i = 0; i < n; i++) {
		double input;
		cin >> input;

		// insert input
		if (minHeap.empty() && maxHeap.empty()) { // first element
			maxHeap.push(input);
		}
		else {
			if (input >= currentMedian) {
				minHeap.push(input);
			}
			else {
				maxHeap.push(input);
			}
		}

		// balance heaps if needed
		int balanceFactor = minHeap.size() - maxHeap.size();
		if (abs(balanceFactor) > 1) {
			balanceHeaps(maxHeap, minHeap);
		}

		currentMedian = getMedian(maxHeap, minHeap);

		cout << fixed << setprecision(1) << currentMedian << "\n";
	}

	return 0;
}

void balanceHeaps(priority_queue<double>& maxHeap, priority_queue<double, vector<double>, greater<double>>& minHeap) {
	if (maxHeap.size() > minHeap.size()) {
		double temp = maxHeap.top();
		maxHeap.pop();
		minHeap.push(temp);
	}
	else {
		double temp = minHeap.top();
		minHeap.pop();
		maxHeap.push(temp);
	}
}

double getMedian(priority_queue<double>& maxHeap, priority_queue<double, vector<double>, greater<double>>& minHeap) {
	double median = 0;

	if (maxHeap.size() != minHeap.size()) { // one element needed
		if (maxHeap.size() > minHeap.size()) {
			median = maxHeap.top();
		}
		else {
			median = minHeap.top();
		}
	}
	else { // two elements needed
		median = (maxHeap.top() + minHeap.top()) / 2;
	}

	return median;
}