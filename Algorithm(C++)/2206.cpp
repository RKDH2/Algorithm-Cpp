#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

string board[1001];
int dist[2][1001][1001];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    queue<tuple<int, int, int>> q;
    fill_n(&dist[0][0][0], 1001 * 1001 * 2, -1);
    //fill(dist, dist+1001*1001*2, -1);
    q.push({ 0, 0, 0 });
    dist[0][0][0] = 1;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int x = get<0>(p), y = get<1>(p), w = get<2>(p);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == '1' && w == 1) continue;
            if (board[nx][ny] == '1' && w == 0) {
                if (dist[1][nx][ny] != -1) continue;
                dist[1][nx][ny] = dist[0][x][y] + 1;
                q.push({ nx, ny, 1 });
            }
            else {
                if (dist[w][nx][ny] != -1) continue;
                q.push({ nx, ny, w });
                dist[w][nx][ny] = dist[w][x][y] + 1;
            }
        }
    }
    if (dist[0][n - 1][m - 1] == -1 && dist[1][n - 1][m - 1] == -1) {
        cout << -1;
    }
    else if (dist[0][n - 1][m - 1] != -1 && dist[1][n - 1][m - 1] != -1) {
        cout << min(dist[0][n - 1][m - 1], dist[1][n - 1][m - 1]);
    }
    else {
        cout << (dist[0][n - 1][m - 1] == -1 ? dist[1][n - 1][m - 1] : dist[0][n - 1][m - 1]);
    }
}