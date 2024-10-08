#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long s = 0, n = 0; cin >> s;

    while (s >= 0) {
        n++;
        s = s - n;
    }

    cout << n - 1 << "\n";
}