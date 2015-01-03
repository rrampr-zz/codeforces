#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > DP;
int range_sum(int n, int a, int b, vector<int>& lookup) {
    int start_index = a + std::max(1 - a, 1 - abs(a - b));
    int end_index = a + std::min(abs(a-b) - 1, n - a);
    int temp = (lookup[end_index] - lookup[start_index - 1]) %  1000000007;
    temp =  (temp + 1000000007) % 1000000007;
    return temp;
}

int getNum(int n,int a,int b,int k) {
    for (int i = 1; i <= n; ++i) {
        DP[0][i] = 1;
    }
    vector<int> lookup;
    for (int i = 1; i <= k; ++i) {
        int sum = 0;
        lookup.push_back(0);
        for (int j = 1; j <= n; ++j) {
            sum += DP[i-1][j];
            sum = sum % 1000000007;
            lookup.push_back(sum);
        }
        for (int j = 1; j <= n; ++j) {
            if (j == b) {
                DP[i][j] = 0;
                continue;
            }
            DP[i][j] = ((range_sum(n, j, b, lookup) - DP[i-1][j]) % 1000000007);
            DP[i][j] = (DP[i][j] + 1000000007) %  1000000007;
        }
        lookup.clear();
    }
    return DP[k][a];
}

int main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    for (int i = 0; i <= k; ++i) {
        DP.push_back(vector<int>());
        for (int j = 0; j <= n; ++j) {
            DP.back().push_back(0);
        }
    }
    std::cout << getNum(n, a, b, k) << "\n";
}
