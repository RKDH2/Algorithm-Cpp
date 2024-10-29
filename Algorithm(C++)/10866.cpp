#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num; cin >> n;
    deque<int> Deque;
    while (n--) {
        string com;
        cin >> com;
        if (com == "push_front") {
            cin >> num;
            Deque.push_front(num);
        }
        else if (com == "push_back") {
            cin >> num;
            Deque.push_back(num);
        }
        else if (com == "pop_front") {
            if (!Deque.empty()) {
                cout << Deque.front() << '\n';
                Deque.pop_front();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (com == "pop_back") {
            if (!Deque.empty()) {
                cout << Deque.back() << '\n';
                Deque.pop_back();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (com == "size") {
            cout << Deque.size() << '\n';
        }
        else if (com == "empty") {
            cout << (Deque.empty() ? 1 : 0) << '\n';
        }
        else if (com == "front") {
            if (!Deque.empty()) cout << Deque.front() << '\n';
            else cout << -1 << '\n';
        }
        else if (com == "back") {
            if (!Deque.empty()) cout << Deque.back() << '\n';
            else cout << -1 << '\n';
        }
    }
}