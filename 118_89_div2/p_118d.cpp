#include <iostream>

using namespace std;

//  dp[n1][n2][0] denotes the number of ways of making beautiful arrangements of n1 footmen and n2 horseman with the first guy in the line
// being a footman. k1 footmen k2 horseman

int dp[101][101][2];

int main() {
    int mod = 100000000;
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    for (int i = 1; i <= k1; ++i) {
        dp[i][0][0] = 1;
        dp[i][0][1] = 0;
    }
    for (int i = 1; i <= k2; ++i) {
        dp[0][i][0] = 0;
        dp[0][i][1] = 1;
    }
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;

    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            //calculate dp[i][j][0] and dp[i][j][1];
            int ct = 0;
            for (int k = 1; k <= k1 &&  i - k >= 0; ++k) {
                ct = (ct + dp[i - k][j][1]) % mod;
            }
            dp[i][j][0] = ct;
            ct = 0;
            for (int k = 1; k <= k2 && j - k >= 0; ++k) {
                ct = (ct + dp[i][j - k][0]) % mod;
            }
            dp[i][j][1] = ct;
        }
    }

    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % mod << "\n";
    return 0;
}