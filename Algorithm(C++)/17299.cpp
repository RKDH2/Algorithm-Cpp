#include <iostream>
#include <stack>
using namespace std;

int nums[1000001];
int bignum[1000001];
int result[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        cin >> bignum[i];
    }
    for (int i = 0; i < n; i++) nums[bignum[i]]++;
    st.push(bignum[n - 1]);
    result[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--) {
        while (!st.empty() && nums[bignum[i]] >= nums[st.top()]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top();
        }
        else {
            result[i] = -1;
        }
        st.push(bignum[i]);
    }
    for (int i = 0; i < n; i++)
        cout << result[i] << ' ';
}