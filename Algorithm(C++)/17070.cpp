#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int board[17][17];
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    // 1: 가로, 2: 세로, 3: 대각선
    queue<tuple<int, int, int>> Q;
    Q.push({ 0, 1, 1 });
    int cnt = 0;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int z = get<2>(cur);
        if (x == n - 1 && y == n - 1) {
            cnt++;
            continue;
        }
        for (int i = 0; i < 3; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= n || nx < 0 || ny >= n || ny < 0) {
                continue;
            }
            if (board[nx][ny] == 1) continue;
            if (z == 1 && i == 1) {
                continue;
            }
            if (z == 2 && i == 0) {
                continue;
            }
            if (i == 2) {
                if (board[nx - 1][ny] == 1 || board[nx][ny - 1] == 1) {
                    continue;
                }
            }
            Q.push({ nx, ny, i + 1 });
        }
    }
    cout << cnt;
}