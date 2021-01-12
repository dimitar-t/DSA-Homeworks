#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
	int n;
	cin >> n;

	unordered_set<string> prefixes;
	unordered_map<string, int> names;

	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;

		string prefix;
		bool printed = false;

		for (char c : name) {
			prefix.append(1, c);

			if (prefixes.find(prefix) == prefixes.end()) {
				prefixes.insert(prefix);

				if (!printed) {
					cout << prefix << endl;
					printed = true;
				}
			}
		}

		names.insert({ name, 1 });

		if (!printed) {
			if (names[name] == 1) {
				cout << name << endl;
			}
			else {
				cout << name << " " << names[name] << endl;
			}
		}

		names[name]++;
	}

	return 0;
}