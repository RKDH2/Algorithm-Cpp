#include <iostream>
#include <vector>

using namespace std;

vector<int> edge[101];
bool visited[101];

int cnt = 0;

void dfs(int v) {
    visited[v] = true;
    for (auto nv : edge[v]) {
        if (!visited[nv]) {
            cnt++;
            dfs(nv);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1);

    cout << cnt;
}