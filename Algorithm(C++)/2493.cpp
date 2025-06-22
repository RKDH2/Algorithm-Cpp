#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
        int Top;
        cin >> Top;
        while (!st.empty() && Top > st.top().first) {
            st.pop();
        }

        if (st.empty()) {
            cout << 0 << ' ';
        }
        else {
            cout << st.top().second << ' ';
        }
        st.push({ Top, i + 1 });
    }
}