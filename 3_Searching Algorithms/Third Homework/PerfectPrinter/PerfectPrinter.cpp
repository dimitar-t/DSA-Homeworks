#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int TIMES_SIZE = 10001;

long long findMinimumTime(vector<long long>& arr, long long min, long long max, long long pages);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long pages, printers;
	cin >> pages >> printers;

	long long min = TIMES_SIZE;
	long long max = 0;
	vector<long long> times;
	for (int i = 0; i < printers; i++) {
		long long time = 0;
		cin >> time;
		times.push_back(time);

		if (time < min) {
			min = time;
		}

		if (time > max) {
			max = time;
		}
	}

	long long minTime = findMinimumTime(times, min, max, pages);

	printf("%lld", minTime);

	return 0;
}

long long findMinimumTime(vector<long long>& arr, long long min, long long max, long long pages) {
	long long start = min;
	long long end = max * pages;

	while (start < end)	{
		long long currentTime = start + (end - start) / 2;
		long long currentPages = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (currentTime / arr[i] >= 1) {
				currentPages += currentTime / arr[i];
			}
		}

		if (currentPages >= pages) {
			end = currentTime;
		}
		else {
			start = currentTime + 1;
		}
	}

	return start;
}