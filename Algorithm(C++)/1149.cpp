#include <iostream>
#include <algorithm>
using namespace std;

int price[1001][3];
int dp[1001][3];
int main() {
    int n;
    cin >> n;
    fill_n(&price[0][0], 1001 * 3, 0);
    fill_n(&dp[0][0], 1001 * 3, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            //특정 수 입력 받을거임
            cin >> price[i][j];
            //price[i][j] = 앞에꺼 3개 중 나 아닌거 두개 중의 최솟값 + 뭔가 
            dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + price[i][j];
        }
    }
    int result = min({ dp[n][0], dp[n][1], dp[n][2] });
    cout << result;
}