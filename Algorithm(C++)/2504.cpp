#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string word;
    cin >> word;
    stack<int> st;
    int sum = 0;
    for (int i = 0; i < word.size(); ++i) {
        sum = 0;
        if (word[i] == '(') {
            st.push(-1);
        }
        else if (word[i] == '[') {
            st.push(-3);
        }
        if (word[i] == ')') {
            if (!st.empty() && st.top() == -1) {
                st.pop();
                st.push(2);
            }
            else if (!st.empty() && st.top() > 0) {
                while (!st.empty() && st.top() > 0) {
                    sum += st.top();
                    st.pop();
                }
                if (st.empty() || !st.empty() && st.top() == -3) {
                    cout << 0;
                    return 0;
                }
                if (!st.empty() && st.top() == -1) {
                    st.pop();
                    sum *= 2;
                    st.push(sum);
                }
            }
            else {
                cout << 0;
                return 0;
            }
        }
        else if (word[i] == ']') {
            if (!st.empty() && st.top() == -3) {
                st.pop();
                st.push(3);
            }
            else if (!st.empty() && st.top() > 0) {
                while (!st.empty() && st.top() > 0) {
                    sum += st.top();
                    st.pop();
                }
                if (st.empty() || !st.empty() && st.top() == -1) {
                    cout << 0;
                    return 0;
                }
                if (!st.empty() && st.top() == -3) {
                    st.pop();
                    sum *= 3;
                    st.push(sum);
                }
            }
            else {
                cout << 0;
                return 0;
            }
        }
    }
    sum = 0;
    while (!st.empty() && st.top() > 0) {
        sum += st.top();
        st.pop();
    }
    if (!st.empty()) {
        cout << 0;
        return 0;
    }
    cout << sum;
}