#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    vector<int> digits;
    int x, sum = 0;
    cin >> x;
    int temp = x;
    while(temp != 0) {
        digits.push_back(temp % 10);
        temp /= 10;
    }
    int t = sqrt(x);
    for (int i = 1; i <= t; ++i) {
        if (x % i) {
            continue;
        }
        vector<int> divs{i, x/i};
        if (divs[0] == divs[1]) {
            divs.pop_back();
        }
        for (auto num : divs) {
            bool flag = false;
            while(num != 0) {
                for (int j = 0; j < digits.size(); ++j) {
                    if (digits[j] == num % 10) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
                num /= 10;
            }
            if (flag) {
                ++sum;      
            }
        }
    }
    cout << sum << "\n";
}