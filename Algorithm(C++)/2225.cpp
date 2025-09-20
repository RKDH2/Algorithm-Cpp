#include <iostream>

using namespace std;

int dp[201][201];
int CAL = 1000000000;

int main() {
    int n, k;
    cin >> n >> k;

    // √ ±‚»≠
    for (int i = 1; i < 201; i++) {
        dp[1][i] = i;
        dp[i][1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % CAL;
        }
    }

    cout << dp[n][k];
}