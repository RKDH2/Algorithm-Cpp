#include <iostream>
using namespace std;

int main() {
    int nums[100001];
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    int st = 0, en = 0;
    const int INF = 0x3f3f3f3f;
    int ans = INF, sum = nums[0];
    if (sum >= s) ans = 1;
    while (st <= en && en < n) {
        int len = en - st + 1;
        if (sum <= s && en < n - 1) {
            en++;
            sum += nums[en];
        }
        else {
            sum -= nums[st];
            st++;
        }
        if (len <= ans && sum >= s) {
            ans = len;
        }
    }
    if (ans != INF)
        cout << ans;
    else
        cout << 0;
}