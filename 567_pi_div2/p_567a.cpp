#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> cities;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		cities.push_back(temp);
	}
	for (int i = 0; i < cities.size(); ++i) {
		int left_min = cities[i] - cities[max(i - 1, 0)];
		int right_min = cities[min(i + 1, n - 1)] - cities[i];
		if (left_min == 0) {
			left_min = INT_MAX;
		}
		if (right_min == 0) {
			right_min = INT_MAX;
		}
		cout << min(left_min, right_min) << " ";
		cout << max(cities[i] - cities.front(), cities.back() - cities[i]) << "\n";
	}
	return 0;
}