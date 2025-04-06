#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> vc[10001];
bool visited[10001];
int weight = 0, node;

void dfs(int v, int w) {
    visited[v] = true;
    if (weight < w) {
        weight = w;
        node = v;
    }
    for (auto nv : vc[v]) {
        if (!visited[nv.second]) {
            dfs(nv.second, w + nv.first);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        vc[a].push_back({ c, b });
        vc[b].push_back({ c, a });
    }

    dfs(1, 0);
    for (int i = 0; i < 10000; ++i) {
        visited[i] = false;
    }
    weight = 0;
    dfs(node, 0);

    cout << weight;
}