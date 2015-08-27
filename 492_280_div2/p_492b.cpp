#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, l;
    vector<int> lanterns;
    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        lanterns.push_back(temp);
    }
    sort(lanterns.begin(), lanterns.end());
    int max_distance = 0;
    for (int i = 0; i < n - 1; ++i) {
        max_distance = max(lanterns[i + 1] - lanterns[i], max_distance);
    }
    cout << fixed;
    cout << setprecision(9) << max((double) max(lanterns.front() - 0, l - lanterns.back()), max_distance/2.0) << "\n";
}