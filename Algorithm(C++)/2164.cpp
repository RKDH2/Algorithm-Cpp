#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    queue<int> card;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        card.push(i);
    }
    while (card.size() > 1) {
        card.pop();
        int front = card.front();
        card.pop();
        card.push(front);
    }

    cout << card.front() << '\n';
}