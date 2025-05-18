#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int nums[100001];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums, nums + n);
    int st = 0, en = 0;
    const int INF = 0x3f3f3f3f;
    int min = INF;
    while (st <= en && en < n) {
        int num = nums[en] - nums[st];
        if (num <= m) {
            en++;
        }
        if (num > m) {
            st++;
        }
        if (m <= num && num < min) {
            min = num;
        }
    }
    cout << min;
}