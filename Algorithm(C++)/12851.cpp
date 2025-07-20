#include <iostream>
#include <queue>
using namespace std;

int visited[100001];

int main() {
    int n, k;
    cin >> n >> k;
    queue<pair<int, int>> Q;
    Q.push({ n, 0 });
    visited[n] = 1;
    int min_dis = -1;
    int ans = 0;
    while (!Q.empty()) {
        int cur_node = Q.front().first;
        int cur_dis = Q.front().second;
        Q.pop();

        visited[cur_node] = 1;

        if (min_dis != -1 && cur_dis > min_dis) {
            break;
        }

        if (cur_node == k) {
            min_dis = cur_dis;
            ans++;
            continue;
        }

        int nx1 = cur_node + 1;
        int nx2 = cur_node - 1;
        int nx3 = cur_node * 2;
        if (nx1 >= 0 && nx1 <= 100000 && visited[nx1] == 0) {
            Q.push({ nx1, cur_dis + 1 });
        }
        if (nx2 >= 0 && nx2 <= 100000 && visited[nx2] == 0) {
            Q.push({ nx2, cur_dis + 1 });
        }
        if (nx3 >= 0 && nx3 <= 100000 && visited[nx3] == 0) {
            Q.push({ nx3, cur_dis + 1 });
        }
    }
    cout << min_dis << '\n' << ans;
}