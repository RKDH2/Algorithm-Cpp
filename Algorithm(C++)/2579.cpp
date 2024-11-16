#include <iostream>
#include <algorithm>
using namespace std;

int st[301];
int dp[301];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> st[i];
    }

    dp[0] = st[0];
    dp[1] = st[1] + st[0];
    dp[2] = max(st[0] + st[2], st[1] + st[2]);

    for (int i = 3; i < n; ++i) {
        dp[i] = st[i] + max(dp[i - 2], dp[i - 3] + st[i - 1]);
    }

    cout << dp[n - 1] << '\n';
}
