#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char boxes[1001][1001];
int fire[1001][1001];

int main() {
    int r, c;
    cin >> r >> c;
    queue<tuple<int, int, int>> bfs_q;

    queue<tuple<int, int, int>> J;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            fire[i][j] = -1;
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            char block; cin >> block;
            boxes[i][j] = block;
            if (block == 'F') {
                bfs_q.push(make_tuple(i, j, 0));
                fire[i][j] = 0;
            }
            if (block == 'J') {
                J.push(make_tuple(i, j, 0));
                if (i == 0 || j == 0 || i == r - 1 || j == c - 1) {
                    cout << "1";
                    return 0;
                }
            }
        }
    }

    const int dx[4] = { 1, -1, 0, 0 };
    const int dy[4] = { 0, 0, 1, -1 };

    // 불 퍼뜨리기 bfs
    while (!bfs_q.empty()) {
        auto cur = bfs_q.front();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int t = get<2>(cur);
        bfs_q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (boxes[nx][ny] == '.' && nx >= 0 && ny >= 0 && nx < r && ny < c) {
                if (fire[nx][ny] == -1) {
                    bfs_q.push(make_tuple(nx, ny, t + 1));
                    fire[nx][ny] = t + 1;
                }
            }
        }
    }


    boxes[get<0>(J.front())][get<1>(J.front())] = '#';

    // 사람 이동 bfs
    while (!J.empty()) {
        auto cur = J.front();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int t = get<2>(cur);
        J.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (boxes[nx][ny] == '.' && nx >= 0 && ny >= 0 && nx < r && ny < c) {
                if (t + 1 < fire[nx][ny] || fire[nx][ny] == -1) {
                    if (nx == r - 1 || ny == c - 1 || nx == 0 || ny == 0) {
                        cout << t + 2;
                        return 0;
                    }
                    boxes[nx][ny] = '*';
                    J.push(make_tuple(nx, ny, t + 1));
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}