#include <iostream>
#include <stack>
using namespace std;

int res[1000001];

int main() {
    int n;
    cin >> n;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (st.empty()) {
            st.push({ i, num });
        }
        else {
            while (!st.empty() && st.top().second < num) {
                res[st.top().first] = num;
                st.pop();
            }
            st.push({ i, num });
        }
    }
    while (!st.empty()) {
        res[st.top().first] = -1;
        st.pop();
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }
}