#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int parent[100001];
int line[100001];

int main() {
    int n, k;
    cin >> n >> k;

    fill(parent, parent + 100001, -1);
    fill(line, line + 100001, -1);
    queue<pair<int, int>> Q;
    Q.push({ n, 0 });
    line[n] = 0;
    while (!Q.empty()) {
        auto p = Q.front();  Q.pop();
        int loc = p.first;
        int cur = p.second;
        int nx1 = loc + 1;
        int nx2 = loc - 1;
        int nx3 = loc * 2;

        if (loc == k) {
            cout << cur << '\n';
            vector<int> res;
            for (int i = loc; i != -1; i = parent[i]) {
                res.push_back(i);
            }
            reverse(res.begin(), res.end());
            for (auto nx : res) {
                cout << nx << ' ';
            }
            break;
        }

        if (nx1 <= 100000 && line[nx1] == -1) {
            line[nx1] = line[loc] + 1;
            parent[nx1] = loc;
            Q.push({ nx1, cur + 1 });
        }
        if (nx2 >= 0 && line[nx2] == -1) {
            line[nx2] = line[loc] + 1;
            parent[nx2] = loc;
            Q.push({ nx2, cur + 1 });
        }
        if (nx3 <= 100000 && line[nx3] == -1) {
            line[nx3] = line[loc] + 1;
            parent[nx3] = loc;
            Q.push({ nx3, cur + 1 });
        }
    }
}