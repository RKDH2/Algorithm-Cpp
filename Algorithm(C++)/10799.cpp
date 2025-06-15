#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int ans = 0;
    string word;
    cin >> word;
    stack<char> st;
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == '(' && word[i + 1] == ')') {
            ans += st.size();
            i++;
        }
        else if (word[i] == '(') {
            st.push(word[i]);
        }
        else if (word[i] == ')') {
            st.pop();
            ans++;
        }
    }
    cout << ans;
}