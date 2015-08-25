#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//Needed help for sqrt(N) solution
int main() {
	unordered_map<int, int> count;
	vector<int> nums, left, right;

	int n, m;
	cin >> n >> m;
	vector<int> ans(m);
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		if (count.find(t) == count.end()) {
			count[t] = 0;
		}
		count[t] += 1;
		nums.push_back(t);
	}

	for (int i = 0; i < m; ++i) {
		int temp, temp1;
		cin >> temp >> temp1;
		left.push_back(temp);
		right.push_back(temp1);
	}
	for (int i = 1; i <= n; ++i) {
		//This is a possible as this if branch executes only order of \sqrt(n) times
		if (count[i] >= i) {
			vector<int> sums;
			//This is basically an accumulator for # of i's from 0 to j (sum[j])
			sums.push_back(0);
			for (int j = 0; j < n; j++) {
				sums.push_back(sums[j] + (nums[j] == i));
			}
			for (int j = 0; j < m; j++) {
				ans[j] += (sums[right[j]] - sums[left[j] - 1] == i);
			}
		}
	}
	for (int j = 0; j < m; j++) {
		cout << ans[j] << "\n";
	}
	return 0;
}