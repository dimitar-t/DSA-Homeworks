#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	stack<int> nums;
	stack<int> undo;
	long long sum = 0;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;

		if (input == -1) {
			if (!undo.empty()) {
				sum -= nums.top();

				undo.push(nums.top());
				nums.pop();
			}
		}
		else if (input == -2) {
			if (!undo.empty()) {
				nums.push(undo.top());

				sum += nums.top();
			}
		}
		else {
			undo = stack<int>();

			nums.push(input);
			undo.push(input);

			sum += input;
		}
	}

	cout << sum << endl;

	return 0;
}
