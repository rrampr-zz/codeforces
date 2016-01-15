#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n - k - 1; ++i) {
		cout << i << " ";
	}
	int t = n;
	for (int j = 0; j < k + 1; ++j) {
		cout << t << " ";
		t--;
	}
	cout << "\n";
	return 0;
}