#include <iostream>
#include <stack>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        stack<pair<int, int>> st;
        if (n == 0) {
            return 0;
        }
        long long maxNum = 0;
        for (int i = 0; i < n; ++i) {
            long long num;
            cin >> num;
            int start = i;
            while (!st.empty() && st.top().second > num) {
                start = st.top().first;
                long long width = i - start;
                long long height = st.top().second;
                maxNum = max(maxNum, width * height);
                st.pop();
            }
            st.push({ start, num });
        }
        while (!st.empty()) {
            long long width = n - st.top().first;
            long long height = st.top().second;
            maxNum = max(maxNum, width * height);
            st.pop();
        }
        cout << maxNum << '\n';
    }
}