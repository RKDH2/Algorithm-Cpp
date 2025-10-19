#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        priority_queue<long long, vector<long long>, greater<long long>> q;

        for (int j = 0; j < n; j++) {
            long long num;
            cin >> num;
            q.push(num);
        }
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }

        long long res = 1;
        while (q.size() > 1) {
            long long num1 = q.top();
            q.pop();
            long long num2 = q.top();
            q.pop();
            long long fee = ((num1 % MOD) * (num2 % MOD)) % MOD;
            res = ((res % MOD) * (fee % MOD)) % MOD;
            q.push(num1 * num2);
        }

        cout << res << '\n';
    }
}