#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    // maximum height with n blocks means k s.t. 1 + 2 + .... + k <= n means I need to get k s.t. k (k + 1) <= 2*n
    int sum = 0, k = 0;
    while (true) {
        sum += (k * (k + 1))/2;
        if (sum == n) {
            cout << k << "\n";
            return 0;
        } else if (sum > n) {
            cout << k - 1 << "\n";
            return 0;
        }
        ++k;
    }
    
    cout << k - 1 << "\n";
    return 0;
}