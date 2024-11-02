#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, cnt = 0;
        cin >> n >> m;

        queue<pair <int, int>> documents;
        priority_queue<int> q;

        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            documents.push({ i, num });
            q.push(num);
        }

        while (!documents.empty()) {
            int idx = documents.front().first;
            int priority = documents.front().second;
            documents.pop();

            if (q.top() == priority) { // 우선순위 4 == 중요도 1 -> X
                q.pop();
                cnt++;

                if (idx == m) { // 1 == 2
                    cout << cnt << '\n';
                    break;
                }
            }
            else {
                documents.push({ idx, priority });
            }
        }
    }
}