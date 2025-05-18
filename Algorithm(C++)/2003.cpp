#include <iostream>
using namespace std;

int main() {
    int nums[10001];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    int st = 0, en = 0;
    int ans = 0, sum = nums[0];
    while (st <= en && en < n) {
        if (sum == m) {
            ans++;
        }
        if (st == en || sum <= m && en < n - 1) {
            en++;
            sum += nums[en];
        }
        else {
            sum -= nums[st];
            st++;
        }
    }
    cout << ans;
}