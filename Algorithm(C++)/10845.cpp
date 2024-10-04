#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        string com;
        cin >> com;
            
        if (com == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (com == "pop") {
            if (q.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (com == "size") {
            cout << q.size() << endl;
        }
        else if (com == "empty") {
            cout << q.empty() << endl;
        }
        else if (com == "front") {
            if (q.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << q.front() << endl;
            }
        }
        else if (com == "back") {
            if (q.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << q.back() << endl;
            }
        }
    }
}