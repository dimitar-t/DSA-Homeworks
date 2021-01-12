#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int getShipsInInterval(int left, int right, int shipLength) {
	return (right - left) / (shipLength + 1);
}

int main() {
	int size, ships, shipLength;
	cin >> size >> ships >> shipLength;

	set<int> guesses;
	guesses.insert(0);
	guesses.insert(size);

	int possibleShips = (size + 1) / (shipLength + 1);

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int query;
		cin >> query;

		guesses.insert(query - 1);

		auto currentIterator = guesses.find(query - 1);
		auto previousIterator = currentIterator != guesses.begin() ? prev(currentIterator) : currentIterator;
		auto nextIterator = next(currentIterator);

		int currentIndex = *currentIterator;
		int previousIndex = *previousIterator;
		int nextIndex = *nextIterator;

		possibleShips -= getShipsInInterval(previousIndex, nextIndex, shipLength) + getShipsInInterval(previousIndex, currentIndex, shipLength) + getShipsInInterval(currentIndex, nextIndex, shipLength);

		if (possibleShips < ships) {
			cout << i + 1;

			return 0;
		}
	}

	cout << -1;

	return 0;
}

