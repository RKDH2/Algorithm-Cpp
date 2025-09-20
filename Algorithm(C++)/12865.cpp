#include <iostream>
#include <vector>

using namespace std;

int dp[101][100001];

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> wv(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> wv[i].first; // i��° ���� ����
        cin >> wv[i].second; // i��° ��ġ ����
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0; // ���԰� 0�� �� �ʱⰪ
    }

    for (int j = 0; j <= k; j++) {
        dp[0][j] = 0; // ���� 0���� ����� �ʱⰪ
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (wv[i].first > j) { // ���࿡ �� ���԰� �� ũ��?
                dp[i][j] = dp[i - 1][j]; // �� i��° ���� �������� ���Ը� ����
            }
            else {
                // max([i��° ������][���� ����-�� ���� ����]�� ��ġ+���� �� ���� ��ġ, [i��° �� �ִ� ��ġ])
                dp[i][j] = max(dp[i - 1][j - wv[i].first] + wv[i].second, dp[i - 1][j]);
            }
        }
    }

    cout << dp[n][k];
}