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
    cin >> v >> e >> k;
    fill(da, da + v + 1, INF);
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        vc[u].push_back({ w, v });
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    da[k] = 0;
    pq.push({ da[k], k }); // 정점 위치, 거리
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (da[cur.Y] != cur.X) continue;

    }
}