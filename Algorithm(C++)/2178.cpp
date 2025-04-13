#include <iostream>
#include <queue>

using namespace std;

int board[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int cnt = 0;
int N, M;

void bfs(int v1, int v2) {
    queue<pair<pair<int, int>, int>> Q;
    Q.push({ {v1, v2},1 });
    board[v1][v2] = 0;

    while (!Q.empty()) {
        int cx = Q.front().first.first;
        int cy = Q.front().first.second;
        int dis = Q.front().second;
        Q.pop();

        if (cx == N - 1 && cy == M - 1) {
            cout << dis;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            // 연결 가능성이 있는 노드
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < N && ny < M && nx >= 0 && ny >= 0) {
                if (board[nx][ny] == 1) {
                    Q.push({ { nx, ny }, dis + 1 });
                    board[nx][ny] = 0;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j) {
            board[i][j] = s[j] - '0';
        }
    }

    bfs(0, 0);
}