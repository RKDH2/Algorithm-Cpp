#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    stack<char> ST;
    int wd2 = word2.length();
    for (int i = 0; i < word1.length(); i++) {
        ST.push(word1[i]);
        if (ST.top() == word2[wd2 - 1]) {
            string wr = "";
            if (ST.size() >= wd2) {
                for (int j = 0; j < wd2; j++) {
                    wr += ST.top();
                    ST.pop();
                }
            }
            reverse(wr.begin(), wr.end());
            if (wr != word2) {
                for (int i = 0; i < wr.length(); i++) {
                    ST.push(wr[i]);
                }
            }
        }
    }
    if (ST.empty()) {
        cout << "FRULA";
        return 0;
    }
    string res = "";
    while (!ST.empty()) {
        res += ST.top();
        ST.pop();
    }
    reverse(res.begin(), res.end());
    cout << res;
}