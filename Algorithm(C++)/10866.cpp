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

        }
    }
}