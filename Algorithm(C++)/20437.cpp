#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        vector<int> alpha[26];
        string word;
        cin >> word;
        int len = word.length();
        int k;
        cin >> k;
        for (int j = 0; j < len; j++) {
            int idx = word[j] - 'a';
            alpha[idx].push_back(j);
        }
        int mini = 100000, maxi = -1;
        for (int r = 0; r < 26; r++) {
            int ssize = (int)alpha[r].size();
            if (ssize >= k) {
                for (int j = 0; j < ssize - k + 1; j++) {
                    mini = min(mini, alpha[r][j + k - 1] - alpha[r][j] + 1);
                    maxi = max(maxi, alpha[r][j + k - 1] - alpha[r][j] + 1);
                }
            }
        }
        if (maxi != -1 && mini != 100000) {
            cout << mini << ' ' << maxi << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}