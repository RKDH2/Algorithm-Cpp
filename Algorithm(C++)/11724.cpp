#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[1001];
bool visited[1001];
int cnt = 0;

void bfs(int v) {
    queue<int> Q;
    Q.push(v);
    visited[v] = true;

    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        for (auto nv : edge[v]) {
            if (!visited[nv]) {
                Q.push(nv);
                visited[nv] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            cnt++;
            bfs(i);
        }
    }

    cout << cnt;
}