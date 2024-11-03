#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp[1000];
    int c[1000];

    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> c[i];
    }

    dp[1] = c[1];
    dp[2] = max(c[1], c[2]);

    for (int i = 3; i <= n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + c[i]);
    }

    cout << dp[n];
}