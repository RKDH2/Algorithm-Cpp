#include <iostream>
#include <stack>
using namespace std;

long long building[80001];

int main() {
    int n;
    cin >> n;
    stack<long long> st;
    for (int i = 1; i <= n; ++i) {
        cin >> building[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && st.top() <= building[i]) {
            st.pop();
        }
        ans += st.size();
        st.push(building[i]);
    }
    cout << ans;
}