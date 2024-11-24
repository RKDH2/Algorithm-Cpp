#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int i = 0; i < n; ++i) {
            cout << "@@@@@";
        }
        cout << '\n';
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "@";
        }
        cout << '\n';
    }
    for (int i = 0; i < n; ++i) {
        for (int i = 0; i < n; ++i) {
            cout << "@@@@@";
        }
        cout << '\n';
    }
    for (int i = 0; i < n * 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "@";
        }
        cout << '\n';
    }
}