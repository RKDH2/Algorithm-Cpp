#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int board[101][101];
bool visited[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int cnt = 0;
int N;
vector<int> V;
int minH = 101;
int maxH = -1;
int curH;

void bfs(int v1, int v2) {
    queue<pair<int, int>> Q;
    Q.push({ v1, v2 });
    visited[v1][v2] = true;

    while (!Q.empty()) {
        int cx = Q.front().first;
        int cy = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < N && ny < N && nx >= 0 && ny >= 0) {
                if (!visited[nx][ny]) {
                    if (board[nx][ny] > curH) {
                        Q.push({ nx, ny });
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            board[i][j] = num;
            if (minH > num) {
                minH = num;
            }
            if (maxH < num) {
                maxH = num;
            }
        }
    }
    V.push_back(1);
    cnt = 0;
    for (curH = minH; curH <= maxH; ++curH) {
        cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!visited[i][j] && board[i][j] > curH) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        V.push_back(cnt);
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                visited[x][y] = false;
            }
        }
    }
    sort(V.begin(), V.end());
    cout << V.back();
}