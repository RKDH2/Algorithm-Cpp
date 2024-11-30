#include <iostream>
#include <algorithm>

using namespace std;

int rope[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, cnt, max_num;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> rope[i];
    }

    sort(rope, rope + n);

    max_num = rope[n - 1];

    for (int i = n - 1; i >= 0; --i) {
        cnt = rope[i] * (n - i);
        if (max_num < cnt) {
            max_num = cnt;
        }
    }

    cout << max_num;
}