#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
vector<pair<int, int>> vc[20001];
int da[20001];
int v, e, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> v >> e >> k;
    fill(da, da + v + 1, INF);
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        vc[u].push_back({ w, v });
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    da[k] = 0;
    pq.push({ da[k], k }); // 가중치, 정점
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (da[cur.Y] != cur.X) continue;
        for (auto nxd : vc[cur.Y]) {
            if (da[nxd.Y] <= da[cur.Y] + nxd.X) continue;
            da[nxd.Y] = da[cur.Y] + nxd.X;
            pq.push({ da[nxd.Y], nxd.Y });
        }
    }
    for (int i = 1; i <= v; ++i) {
        if (da[i] == INF) {
            cout << "INF" << '\n';
        }
        else {
            cout << da[i] << '\n';
        }
    }
}