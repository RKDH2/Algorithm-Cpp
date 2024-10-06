#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    int dp[11] = { 1, 2, 4 };

    cin >> t;

    for (int i = 3; i < 11; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    while (t--) {
        cin >> n;
        cout << dp[n - 1] << endl;
    }
}