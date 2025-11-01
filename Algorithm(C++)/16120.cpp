#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string word;
    cin >> word;

    stack<char> st;
    int cnt = 0;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == 'P') {
            cnt++;
            st.push(word[i]);
        }
        else if (cnt >= 2 && word[i] == 'A') {
            if (i == word.length() - 1) {
                cout << "NP";
                return 0;
            }
            if (word[i + 1] == 'P') {
                st.pop(); st.pop();
                cnt -= 2;
            }
            else {
                cout << "NP";
                return 0;
            }
        }
        else {
            cout << "NP";
            return 0;
        }
    }
    if (st.size() == 1) cout << "PPAP";
    else cout << "NP";
}