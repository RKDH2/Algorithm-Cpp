#include <iostream>
using namespace std;

int card[10001];
int dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        card[i] = num;
    }
    fill_n(dp, n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int maxn = 0;
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(maxn, card[j] + dp[i - j]);
            maxn = dp[i];
        }
    }
    cout << dp[n];
}