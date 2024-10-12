#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, st[8]; cin >> t;
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> st[j];
        }

        st[0] += st[4], st[1] += st[5], st[2] += st[6], st[3] += st[7];
        st[0] < 1 ? st[0] = 1 : 0, st[1] < 1 ? st[1] = 1 : 0, st[2] < 1 ? st[2] = 0 : 0;

        cout << st[0] * 1 + st[1] * 5 + st[2] * 2 + st[3] * 2 << '\n';
    }
}