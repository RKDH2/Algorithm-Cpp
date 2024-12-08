#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> vc;
vector<int> c;

int N, K; // 보석 개수, 가방 개수
long long total = 0;

long long solve() {
    sort(vc.begin(), vc.end());
    sort(c.begin(), c.end());

    priority_queue<int> pq;
    int idx = 0;

    for (int weg : c) {
        // 보석 개수가 넘어가거나 가방 무게가 넘어가거나
        while (idx < N && weg >= vc[idx].first) {
            pq.push(vc[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        int M, V;
        cin >> M >> V;
        vc.push_back({ M, V });
    }
    for (int i = 0; i < K; ++i) {
        int C;
        cin >> C;
        c.push_back(C);
    }

    cout << solve();
}