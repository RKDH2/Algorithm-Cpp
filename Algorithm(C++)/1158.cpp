#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    queue<int> Q;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) Q.push(i);
    cout << "<";

    while (Q.size() > 1) {
        for (int i = 1; i < k; ++i) {
            int tmp = Q.front();
            Q.pop();
            Q.push(tmp);
        }

        cout << Q.front() << ", ";
        Q.pop();
    }
    cout << Q.front() << ">\n";
}