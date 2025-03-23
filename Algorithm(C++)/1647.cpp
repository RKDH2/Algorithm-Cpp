#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> piii;

int parent[100001];
int s[100001];

int Find(int x) {
    if (parent[x] == -1) {
        return x;
    }
    else {
        int root = Find(parent[x]);
        parent[x] = root;
        return root;
    }
}

void Union(int x, int y) {
    int rx, ry;
    rx = Find(x); ry = Find(y);
    if (rx != ry) {
        if (s[rx] < s[ry]) {
            parent[rx] = ry;
            s[ry] += s[rx];
        }
        else {
            parent[ry] = rx;
            s[rx] += s[ry];
        }
    }
}

int main() {
    int N, M, total = 0;
    cin >> N >> M;

    priority_queue<piii, vector<piii>, greater<piii>> tree;

    for (int i = 0; i < N; ++i) {
        parent[i] = -1;
        s[i] = 1;
    }
    int A, B, C;
    for (int i = 0; i < M; ++i) {
        cin >> A >> B >> C;
        tree.push({ C, {A, B} });
    }

    int maxv = 0;
    while (!tree.empty()) {
        int v1 = tree.top().second.first;
        int v2 = tree.top().second.second;
        int e = tree.top().first;

        tree.pop();
        if (Find(v1) != Find(v2)) {
            Union(v1, v2);
            total += e;
            maxv = e;
        }
    }

    cout << total - maxv << '\n';
}