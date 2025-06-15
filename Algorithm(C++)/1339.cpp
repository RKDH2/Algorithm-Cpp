#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string word_f, word_s;
    cin >> word_f >> word_s;
    while (0 < word_s.length()) {
        if (word_s[word_s.length() - 1] == 'A') {
            word_s.erase(word_s.length() - 1, 1);
        }
        else if (word_s[word_s.length() - 1] == 'B') {
            word_s.erase(word_s.length() - 1, 1);
            reverse(word_s.begin(), word_s.end());
        }
        if (word_f == word_s) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}