#include <iostream>

using namespace std;

int nums[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    for (int x = 0; x < m; ++x) {
        int i, j;
        cin >> i >> j;
        if (i == j) {
            cout << nums[i] << '\n';
        }
        else {
            int total = 0;
            for (int y = i; y <= j; ++y) {
                total += nums[y];
            }
            cout << total << '\n';
        }
    }
}