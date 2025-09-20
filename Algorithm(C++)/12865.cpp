#include <iostream>
#include <vector>

using namespace std;

int dp[101][100001];

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> wv(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> wv[i].first; // i번째 무게 저장
        cin >> wv[i].second; // i번째 가치 저장
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0; // 무게가 0일 때 초기값
    }

    for (int j = 0; j <= k; j++) {
        dp[0][j] = 0; // 물건 0개를 고려한 초기값
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (wv[i].first > j) { // 만약에 내 무게가 더 크면?
                dp[i][j] = dp[i - 1][j]; // 내 i번째 물건 전까지의 무게를 저장
            }
            else {
                // max([i번째 전에서][현재 무게-내 물건 무게]의 가치+현재 내 물건 가치, [i번째 전 최대 가치])
                dp[i][j] = max(dp[i - 1][j - wv[i].first] + wv[i].second, dp[i - 1][j]);
            }
        }
    }

    cout << dp[n][k];
}