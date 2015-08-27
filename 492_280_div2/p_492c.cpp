#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Exam {
    long long grade;
    long long grade_essay;

    Exam(long long g, long long g_e) : grade(g), grade_essay(g_e) {}
    Exam() : grade(0), grade_essay(0) {}
};

Exam grades[100001];

int main() {
    long long n, r, avg, deficit = 0;
    cin >> n >> r >> avg;
    for (int i = 0; i < n; ++i) {
        long long temp, temp1;
        cin >> temp >> temp1;
        if (temp > avg) {
            deficit -= (temp - avg);
        } else if (avg > temp) {
            deficit += (avg - temp);
        }
        grades[i] = Exam(temp, temp1);
    }
    if (deficit <= 0) {
        cout << 0 << "\n";
        return 0;
    }
    long long points = deficit;
    sort(grades, grades + n, [](const Exam &a, const Exam &b) {return a.grade_essay < b.grade_essay;});
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        if (points == 0) {
            break;
        }
        if (grades[i].grade >= r) {
            continue;
        }
        sum += min((r - grades[i].grade), points) * grades[i].grade_essay;
        points -= min(r - grades[i].grade, points);
    }
    cout << sum << "\n";
}