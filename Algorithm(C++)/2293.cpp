#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001]; // dp[x] = x���� ����� ����� ��

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coin(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    dp[0] = 1;
    // 0���� ����� ���� '�� ����' 1������ ���� (����(base case) ����)
// �� ���� ���п� dp[j - coin]�� 0�� ���� �ùٸ� ����� �� ���� ����

	for (int i = 0; i < n; i++) { // i��° ���� ����
		for (int j = coin[i]; j <= k; j++) { // ���� �ݾ� j�� ����� ����� �� ���
			dp[j] += dp[j - coin[i]];
            // dp[j] += dp[j - coin[i]] �� �ǹ�:
            // "j���� ����� ���� coin[i]�� �ϳ� ������� ��,
            // ������ (j - coin[i])���� ����� ��� ����� ���� ���Ѵ�."
            //
            // ��) coin[i] = 5, j = 7�̶��
            // dp[7] += dp[7 - 5] = dp[7] += dp[2]
            // �� 7���� ���� ��, '5���� �ϳ� �ְ� + (2���� ����� ��� ���)'�� �̾���� ��.
            //
            // ��, (���� ������ �ϳ� ���) + (���� �ݾ��� ����� �����)�� ��ġ�� ����.
        }
    }
    cout << dp[k];
}