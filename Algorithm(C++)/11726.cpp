#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int dp[10001];
    dp[1] = 1;
    dp[2] = 2;
    /*vector<int> v(10001);*/

    for (int i = 3; i <= n; ++i) {
        dp[i] = ((dp[i - 1] + dp[i - 2]) % 10007);
    }

    cout << dp[n] << '\n';
}