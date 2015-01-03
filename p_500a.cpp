#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>
#include <array>


using namespace std;


int main() {
    size_t n, t;
    cin >> n >> t;
    vector<int> ptls;
    for (size_t i = 0; i < n - 1; ++i) {
        int k;
        cin >> k;
        ptls.push_back(k);
    }
    int cur_cell = 1;
    while (true) {
        if (cur_cell > t) {
            cout << "NO";
            return 0;
        }
        if (cur_cell == t) {
            cout << "YES";
            return 0;
        }
        cur_cell = cur_cell + ptls[cur_cell - 1];
    }
    return 0;
}
