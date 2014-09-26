#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using std::cout;
using std::cin;
using std::string;
using std::ostringstream;
int main() {
  int n;
  string word;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> word;
    if (word.size() > 10) {
      ostringstream ss;
      ss << (word.size() - 2);
      word = word.front()
	     + ss.str()
             + word.back();
    }
    cout << word << "\n";
  }
  return 0;
}
