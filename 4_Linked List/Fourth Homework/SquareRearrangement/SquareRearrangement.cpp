#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

list<int>::iterator advance(list<int>& collection, list<int>::iterator it, int positions);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, shifts, spaces;
	cin >> n >> shifts >> spaces;

	list<int> squares;
	for (int i = 0; i < n; i++) {
		int square;
		cin >> square;
		squares.push_back(square);
	}
	
	list<int>::iterator start = squares.begin();
	bool toBreak = false;
	while (true) {
		list<int>::iterator end = advance(squares, start, shifts - 1);
		
		if (end == prev(squares.end(), 1)) {
			toBreak = true;
		}

		while (start != end) {
			int toMove = *start;
			list<int>::iterator advanced = next(start, 1);
			squares.erase(start);
			squares.insert(next(end, 1), toMove);
			start = advanced;
		}

		if (!toBreak) {
			start = advance(squares, end, shifts + spaces);
		}
		else {
			break;
		}
	}

	for (const int& square : squares) {
		printf("%d", square);
		printf("%s", "\n");
	}

	return 0;
}

list<int>::iterator advance(list<int>& collection, list<int>::iterator it, int positions) {
	for (int i = 0; i < positions; i++) {
		if (it == prev(collection.end(), 1)) {
			return it;
		}

		it++;
	}

	return it;
}