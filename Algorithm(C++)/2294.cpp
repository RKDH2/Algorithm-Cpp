#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001]; // dp[i] = A (금액 i를 맞추기 위한 최소 동전 개수 A -> 코인 개수)

int main() {
    int n, k;
    cin >> n >> k;
    dp[0] = 0; // 0원을 위해서는 0개가 필요하다
    for (int i = 1; i <= k; i++) dp[i] = 10001; // 불가능한 경우
    vector<int> coin(n + 1); // 동전 하나의 금액
    for (int i = 1; i <= n; i++) cin >> coin[i];
    for (int i = 1; i <= k; i++) { // 현재 돈 i
        for (int j = 1; j <= n; j++) { // j번째는 현재 동전 (coin[j] -> 현재 동전 값을 의미)
            if (coin[j] <= i) { // 현재 코인이 현재 돈보다 작을 때 (넣을 가능성이 있을경우)
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
                // min(j번째(현재 동전) 선택 안 했을 경우, 선택했을 경우)
                // dp[i] -> 전 구성 요소(코인 개수)
                // i - coin[j] -> 현재 돈 i의 현재 동전의 값(돈)을 뺀다 (현재 동전을 넣기 위해)
                // 현재 돈에 현재 코인 값(돈)을 뺀 구성(dp[i - coin[j]])에 코인 j넣기(+1 -> 개수 추가)
            }
        }
    }
    if (dp[k] == 10001) cout << -1;
    else cout << dp[k];
}