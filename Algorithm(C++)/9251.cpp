#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int idx[1001][1001];

int main() {
    string word1, word2;
    cin >> word1 >> word2;

    for (int i = 1; i <= word1.length(); i++) {
        for (int j = 1; j <= word2.length(); j++) {
            if (word1[i - 1] == word2[j - 1]) {
                idx[i][j] = idx[i - 1][j - 1] + 1;
            }
            else {
                idx[i][j] = max(idx[i - 1][j], idx[i][j - 1]);
            }
        }
    }

    cout << idx[word1.length()][word2.length()] << '\n';
}