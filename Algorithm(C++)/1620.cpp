#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    map<string, int> mp1;
    map<int, string> mp2;

    for (int i = 1; i <= N; ++i) {
        string poke;
        cin >> poke;
        mp1[poke] = i;
        mp2[i] = poke;
    }
    for (int i = 0; i < M; ++i) {
        bool flag = true;
        string word;
        cin >> word;
        for (int i = 0; i < word.length(); ++i) {
            if (!isdigit(word[i])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << mp2[stoi(word)] << '\n';
        }
        else {
            cout << mp1[word] << '\n';
        }
    }
}