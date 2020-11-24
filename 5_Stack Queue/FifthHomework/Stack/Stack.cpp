#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "Stack.h"

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cin.ignore();

	Stack<int> stack;
	for (int i = 0; i < n; i++) {
		string input;
		getline(cin, input);

		if (input == "pop") {
			stack.pop();
		}
		else if (input == "peek") {
			printf("%d\n", stack.peek());
		}
		else if (input == "min") {
			printf("%d\n", stack.min());
		}
		else {
			int toPush = stoi(input.substr(input.find(" "), input.length()));
			stack.push(toPush);
		}
	}

	return 0;
}
