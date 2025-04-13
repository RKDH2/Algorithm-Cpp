#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, K;
int board[101][101];
bool visited[101][101];
vector<int> v;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int cnt = 0;

void bfs(int v1, int v2) {
    queue<pair<int, int>> Q;
    Q.push({ v1, v2 });
    visited[v1][v2] = true;
    cnt++;

    while (!Q.empty()) {
        int cx = Q.front().first;
        int cy = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; ++i) {
            // 연결 가능성이 있는 노드
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < N && ny < M && nx >= 0 && ny >= 0) {
                if (board[nx][ny] == 0 && !visited[nx][ny]) {
                    cnt++;
                    Q.push({ nx, ny });
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    cin >> M >> N >> K;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < K; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2; ++j) {
            for (int k = y1; k < y2; ++k) {
                board[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 0 && visited[i][j] == false) {
                cnt = 0;
                bfs(i, j);
                v.push_back(cnt);
            }
        }
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (auto n : v) {
        cout << n << ' ';
    }
}