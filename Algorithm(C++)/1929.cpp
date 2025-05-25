#include <iostream>
using namespace std;
int arr[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, n;

    cin >> m >> n;
    arr[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (arr[i] == 1) {
            continue;
        }
        for (int j = i * 2; j <= n; j = j + i) {
            arr[j] = 1;
        }
    }
    for (int i = m; i <= n; ++i) {
        if (arr[i] == 0) {
            cout << i << '\n';
        }
    }
}