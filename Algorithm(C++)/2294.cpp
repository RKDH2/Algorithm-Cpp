#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001]; // dp[i] = A (�ݾ� i�� ���߱� ���� �ּ� ���� ���� A -> ���� ����)

int main() {
    int n, k;
    cin >> n >> k;
    dp[0] = 0; // 0���� ���ؼ��� 0���� �ʿ��ϴ�
    for (int i = 1; i <= k; i++) dp[i] = 10001; // �Ұ����� ���
    vector<int> coin(n + 1); // ���� �ϳ��� �ݾ�
    for (int i = 1; i <= n; i++) cin >> coin[i];
    for (int i = 1; i <= k; i++) { // ���� �� i
        for (int j = 1; j <= n; j++) { // j��°�� ���� ���� (coin[j] -> ���� ���� ���� �ǹ�)
            if (coin[j] <= i) { // ���� ������ ���� ������ ���� �� (���� ���ɼ��� �������)
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
                // min(j��°(���� ����) ���� �� ���� ���, �������� ���)
                // dp[i] -> �� ���� ���(���� ����)
                // i - coin[j] -> ���� �� i�� ���� ������ ��(��)�� ���� (���� ������ �ֱ� ����)
                // ���� ���� ���� ���� ��(��)�� �� ����(dp[i - coin[j]])�� ���� j�ֱ�(+1 -> ���� �߰�)
            }
        }
    }
    if (dp[k] == 10001) cout << -1;
    else cout << dp[k];
}