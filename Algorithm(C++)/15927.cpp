#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string word;
    cin >> word;
    int res = 0, cnt = 0;
    for (int i = 0; i < word.size() - 1; i++) {
        if (word[i] == word[i + 1]) cnt++;
    }
    if (cnt == word.size() - 1) {
        cout << -1;
        return 0;
    }
    string w = word;
    reverse(w.begin(), w.end());
    if (w == word) {
        cout << word.size() - 1;
        return 0;
    }
    cout << word.size();
    return 0;
}