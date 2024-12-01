#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> edge[1001];
bool visited[1001];

void dfs(int v) {
    cout << v << ' ';
    visited[v] = true;
    for (auto nv : edge[v]) {
        if (!visited[nv]) {
            dfs(nv);
        }
    }
}

void bfs(int v) {
    queue<int> Q;
    fill(visited, visited + 1001, false);
    Q.push(v);
    visited[v] = true;

    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        cout << v << ' ';
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

    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 1; i < N + 1; ++i) {
        sort(edge[i].begin(), edge[i].end());
    }

    dfs(V);
    cout << '\n';
    bfs(V);
}