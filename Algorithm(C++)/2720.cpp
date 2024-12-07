#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, money;
    int coin[4] = { 25, 10, 5, 1 };
    cin >> T;

    while (T--) {
        cin >> money;
        for (int i = 0; i < 4; ++i) {
            cout << money / coin[i] << ' ';
            money %= coin[i];
        }
        cout << '\n';
    }
}