#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, X; cin >> n;
    queue<int> Queue;
    while (n--) {
        string com;
        cin >> com;
        if (com == "push") {
            cin >> X;
            Queue.push(X);
        }
        else if (com == "pop") {
            if (!Queue.empty()) {
                cout << Queue.front() << '\n';
                Queue.pop();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (com == "size") {
            cout << Queue.size() << '\n';
        }
        else if (com == "empty") {
            cout << (Queue.empty() ? 1 : 0) << '\n';
        }
        else if (com == "front") {
            if (!Queue.empty()) cout << Queue.front() << '\n';
            else cout << -1 << '\n';
        }
        else if (com == "back") {
            if (!Queue.empty()) cout << Queue.back() << '\n';
            else cout << -1 << '\n';
        }
    }
}