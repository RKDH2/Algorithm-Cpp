#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[10001];

int main() {
    int n;
    double m; int m2;
    while (true) {
        for (int i = 0; i < 10001; i++) dp[i] = 0;
        vector<pair<int, int>> cp;
        cp.push_back({ 0, 0 });
        cin >> n >> m;
        m2 = (m + 0.005) * 100;
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++) {
            int c; double p; int p2;
            cin >> c >> p;
            p2 = (p + 0.005) * 100;
            cp.push_back({ p2, c });
        }
        sort(cp.begin(), cp.end());
        for (int i = 1; i <= 10000; i++) {
            for (int j = 1; j <= n; j++) {
                if (cp[j].first > i) {
                    break;
                }
                else {
                    dp[i] = max(dp[i], dp[i - cp[j].first] + cp[j].second);
                }
            }
        }
        cout << dp[m2] << '\n';
    }
}