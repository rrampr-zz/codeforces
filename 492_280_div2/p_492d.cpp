#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fraction {
    int num;
    int denom;
    Fraction(int n, int d): num(n), denom(d) {}

    bool operator==(const Fraction& other) const {
        return ((long long) num) * other.denom == ((long long) denom) * other.num;
    }

    bool operator<(const Fraction& other) const {
        return ((long long) num) * other.denom < ((long long) denom) * other.num;
    }
};

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<Fraction> hits;
    hits.reserve(x + y + 1);
    for (int i = 1; i <= x; ++i) {
        hits.push_back(Fraction(i, x));
    }
    for (int i = 1; i <= y; ++i) {
        hits.push_back(Fraction(i, y));
    }
    //hits is of size x + y now we can sort it in O(nlogn)
    sort(hits.begin(), hits.end());
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        k -= 1;
        k %= hits.size();
        if ((k != hits.size() && (hits[k] == hits[k + 1])) || (k != 0 && (hits[k] == hits[k - 1])))  {
            cout << "Both\n";
        } else if (hits[k].denom == x) {
            cout << "Vanya\n";
        } else {
            cout << "Vova\n";
        }
    }
    return 0;
}