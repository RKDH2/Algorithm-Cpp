#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> ST;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int com;
        cin >> com;

        if (com == 1) {
            int x;
            cin >> x;
            ST.push(x);
        }
        else if (com == 2) {
            if (!ST.empty()) {
                cout << ST.top() << "\n";
                ST.pop();
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if (com == 3) {
            cout << ST.size() << "\n";
        }
        else if (com == 4) {
            if (ST.empty()) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        else if (com == 5) {
            if (!ST.empty()) {
                cout << ST.top() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
    }
}