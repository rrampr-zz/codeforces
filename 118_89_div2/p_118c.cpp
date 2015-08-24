#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

struct Comparator {
	int digit;
	Comparator(int k) : digit(k) {}

	bool operator()(const int first, const int second) const {
		if (abs(first - digit) == abs(second - digit)) {
			return second < first;
		}
		return abs(first - digit) < abs(second - digit);
	}
};

struct Solution {
	int cost;
	string number;

	Solution(int c, string n) : cost(c), number(n) {}

	bool operator<(const Solution& other) const {
		if (cost != other.cost) {
			return cost < other.cost;
		} else {
			return number < other.number;
		}
	}
};

set<Solution> sols;

int main() {
	int n, k;
	cin >> n >> k;
	string number;
	cin >> number;


	for (int i = 0; i <= 9; ++i) {
		Comparator cmp(i);
		map<int, int, Comparator> avail(cmp);
		int num_spots_to_fill = k, cost = 0, idx = 0, to_skip = 0, digit_to_skip = 0;
		for (auto digit : number) {
			if (digit - '0' == i) {
				num_spots_to_fill--;
			} else {
				avail[digit - '0'] += 1;
			}
			++idx;
		}

		if (num_spots_to_fill <= 0) {
			sols.insert(Solution(0, number));
			continue;
		}

		map<int, int, Comparator> to_be_used(cmp);
		int temp = num_spots_to_fill;
		for (auto entry : avail) {
			if (num_spots_to_fill <= 0) {
				break;
			}
			to_be_used[entry.first] = min(entry.second, num_spots_to_fill);
			if (num_spots_to_fill < entry.second) {
				to_skip = entry.second - num_spots_to_fill;
				digit_to_skip = entry.first;
			}
			num_spots_to_fill -= entry.second;
		}

		num_spots_to_fill = temp;
		string new_number;
		for (auto digit : number) {
			if (digit - '0' != i && to_be_used[digit - '0'] != 0 && num_spots_to_fill > 0) {
				if (digit - '0' == digit_to_skip && to_skip > 0 && digit_to_skip < i) {
					new_number.push_back(digit);
					to_skip--;
					continue;
				}
				new_number.push_back(i + '0');
				cost += abs((digit - '0') - i);
				to_be_used[digit - '0'] -= 1;
				num_spots_to_fill--;
			} else {
				new_number.push_back(digit);
			}
		}

		sols.insert(Solution(cost, new_number));
		//remove zeros
	}

	cout << sols.begin() -> cost << "\n";
	cout << sols.begin() -> number << "\n";

	return 0;
}