#include <iostream>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string word;
    cin >> word;

    int count[27] = { 0, };

    for (int i = 0; i < word.size(); ++i) {
        if ('a' <= word[i] && word[i] <= 'z') {
            word[i] -= 32;
        }
        count[word[i] - 'A']++;
    }

    int max_i = 0;

    for (int i = 0; i < 27; ++i) {
        if (count[max_i] < count[i]) {
            max_i = i;
        }
    }

    int cnt = 0;

    for (int i = 0; i < 27; ++i) {
        if (count[max_i] == count[i]) {
            cnt++;
        }
    }

    if (cnt > 1) {
        cout << "?";
    }
    else {
        cout << (char)(max_i + 'A');
    }
}