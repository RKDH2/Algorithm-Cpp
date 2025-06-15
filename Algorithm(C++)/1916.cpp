#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<vector<pair<int, int>>> arr(1001);
int dist[1001];
const int INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    fill_n(dist, 1001, INF);

    for (int i = 0; i < m; ++i) {
        int city_s, city_e, price;
        cin >> city_s >> city_e >> price;
        arr[city_s].push_back({ price,  city_e });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int >>> pq;
    int a, b;
    cin >> a >> b;
    pq.push({ 0, a });
    dist[a] = 0;
    while (!pq.empty()) {
        int distance = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] != distance) continue;
        for (auto& edge : arr[cur]) {
            if (dist[edge.second] > distance + edge.first) {
                dist[edge.second] = distance + edge.first;
                pq.push({ dist[edge.second], edge.second });
            }

        }
    }
    cout << dist[b];
}