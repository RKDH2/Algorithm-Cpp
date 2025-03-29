#include <iostream>

using namespace std;

int parent[1001];
int s[1001];
int journey[1001];

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
    int rx = Find(x); int ry = Find(y);
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
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        parent[i] = -1;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int city;
            cin >> city;
            if (city == 1) {
                Union(i, j);
            }
            else {
                continue;
            }
        }
    }
    for (int i = 0; i < M; ++i) {
        cin >> journey[i];
    }

    for (int i = 0; i < M - 1; ++i) {
        if (Find(journey[i]) != Find(journey[i + 1])) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}