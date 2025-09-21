#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[21][101];

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> lj(n + 1);
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= 100; j++) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> lj[i].first;
    }
    for (int j = 1; j <= n; j++) {
        cin >> lj[j].second;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 99; j++) {
            if (lj[i].first > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j - lj[i].first] + lj[i].second, dp[i - 1][j]);
            }
        }
    }

    cout << dp[n][99];
}