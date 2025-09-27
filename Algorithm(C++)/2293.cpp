#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001]; // dp[x] = x원을 만드는 경우의 수

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coin(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    dp[0] = 1;
    // 0원을 만드는 경우는 '빈 조합' 1가지로 정의 (기저(base case) 조건)
// 이 정의 덕분에 dp[j - coin]이 0일 때도 올바른 경우의 수 누적 가능

	for (int i = 0; i < n; i++) { // i번째 동전 선택
		for (int j = coin[i]; j <= k; j++) { // 현재 금액 j를 만드는 경우의 수 계산
			dp[j] += dp[j - coin[i]];
            // dp[j] += dp[j - coin[i]] 의 의미:
            // "j원을 만들기 위해 coin[i]를 하나 사용했을 때,
            // 나머지 (j - coin[i])원을 만드는 모든 경우의 수를 더한다."
            //
            // 예) coin[i] = 5, j = 7이라면
            // dp[7] += dp[7 - 5] = dp[7] += dp[2]
            // → 7원을 만들 때, '5원을 하나 넣고 + (2원을 만드는 모든 경우)'를 이어붙인 것.
            //
            // 즉, (현재 동전을 하나 사용) + (남은 금액을 만드는 방법들)을 합치는 원리.
        }
    }
    cout << dp[k];
}