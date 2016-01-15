#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int n, reg, max_size = 0;
    cin >> n;
    string word;
    char enter;
    set<int> room;
    for (int i = 0; i < n; ++i) {
        cin >> enter >> reg;
        if (enter == '+') {
            room.insert(reg);
        } else {
            if (room.find(reg) == room.end()) {
                max_size += 1;
            } else {
                room.erase(reg);
            }
        }
        if (room.size() > max_size) {
            max_size = room.size();
        }
    }
    cout << max_size << "\n";
    return 0;
}
