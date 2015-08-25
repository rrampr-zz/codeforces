#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string int_to_string(int k) {
    std::ostringstream ss;
        ss << k;
        return ss.str();
}

int main() {
    int n;
    string output;
    cin >> n;
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < 2 * i; ++j) {
            output.push_back(' ');
        }
        int mid = n - i;
        for (int j = 0; j < mid; ++j) {
            output.append(int_to_string(j) + " ");
        }
        for (int j = mid; j >= 0; --j) {
            output.append(int_to_string(j) + " ");
        }
        output.pop_back();
        output.push_back('\n');
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * (i + 1); ++j) {
            output.push_back(' ');
        }
        int mid = n - i - 1;
        for (int j = 0; j < mid; ++j) {
            output.append(int_to_string(j) + " ");
        }
        for (int j = mid; j >= 0; --j) {
            output.append(int_to_string(j) + " ");
        }
        output.pop_back();
        output.push_back('\n');
    }
    cout << output << "\n";
    return 0;
}