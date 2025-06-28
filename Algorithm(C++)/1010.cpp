#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int dp[30][30];
        fill_n(&dp[0][0], 30 * 30, 0);
        int left, right;
        cin >> left >> right;
        for (int i = 0; i <= right; ++i) {
            dp[i][i] = dp[i][0] = 1;
        }
        for (int i = 2; i <= right; ++i) {
            for (int j = 1; j <= i - 1; ++j) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        cout << dp[right][left] << '\n';
    }
}