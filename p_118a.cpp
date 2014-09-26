#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;
int main() {
  string word;
  string newWord = "";
  cin >> word;
  char vowels[] = {'A','E','I','O','U', 'a', 'e', 'i', 'o', 'u', 'y'};
  for (int i = 0; i < word.size(); ++i) {
    if (find(vowels, vowels + 11, word[i]) ==
	vowels + 11) {
      newWord.push_back('.');
      newWord.push_back(tolower(word[i]));
    }
  }
  cout << newWord;
  return 0;
}
