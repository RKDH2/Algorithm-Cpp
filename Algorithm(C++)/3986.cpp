#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int n, ans = 0, result = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        stack<char> st;
        string word;
        cin >> word;
        for (int j = 0; j < word.size(); ++j) {
            if (st.empty()) st.push(word[j]);
            else if (word[j] == st.top()) {
                st.pop();
            }
            else {
                st.push(word[j]);
            }
        }
        if (st.empty()) {
            result++;
        }
    }
    cout << result;
}