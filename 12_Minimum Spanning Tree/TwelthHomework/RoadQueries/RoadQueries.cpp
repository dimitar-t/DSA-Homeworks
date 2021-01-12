#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void connectCities(vector<int>& component, int from, int to);
bool areCitiesConnected(vector<int>& component, int from, int to);

int main() {
	int cities, roads;
	cin >> cities >> roads;

	// init component array
	vector<int> component(cities + 1);

	for (int i = 0; i < component.size(); i++) {
		component[i] = i;
	}

	for (int i = 0; i < roads; i++) {
		int from, to;
		cin >> from >> to;

		connectCities(component, from, to);
	}

	// process queries
	int queries;
	cin >> queries;

	vector<bool> result;

	for (int i = 0; i < queries; i++) {
		int type, from, to;
		cin >> type >> from >> to;

		if (type == 1) {
			result.push_back(areCitiesConnected(component, from, to));
		}
		else {
			connectCities(component, from, to);
		}
	}

	for (bool answer : result) {
		cout << answer;
	}

	return 0;
}

void connectCities(vector<int>& component, int from, int to) {
	int oldComponent = component[from];
	int newComponent = component[to];

	for (int i = 1; i < component.size(); i++) {
		if (component[i] == oldComponent) {
			component[i] = newComponent;
		}
	}
}

bool areCitiesConnected(vector<int>& component, int from, int to) {
	return component[from] == component[to];
}