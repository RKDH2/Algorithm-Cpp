#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string word;
    cin >> word;
    stack<char> left;
    stack<char> right;
    int m;
    cin >> m;
    for (auto wd : word) {
        left.push(wd);
    }
    for (int i = 0; i < m; ++i) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') {
            if (left.empty()) {
                continue;
            }
            right.push(left.top());
            left.pop();
        }
        else if (cmd == 'D') {
            if (right.empty()) {
                continue;
            }
            left.push(right.top());
            right.pop();
        }
        else if (cmd == 'B') {
            if (left.empty()) {
                continue;
            }
            left.pop();
        }
        else if (cmd == 'P') {
            char w;
            cin >> w;
            left.push(w);
        }
    }
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }
}