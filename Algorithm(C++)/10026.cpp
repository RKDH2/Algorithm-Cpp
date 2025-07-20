#include <iostream>
#include <queue>
using namespace std;

char board[101][101];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[101][101];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    queue<pair<int, int>> Q;
    int cnt = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == false) cnt++;
            Q.push({ i, j });
            visited[i][j] = true;
            while (!Q.empty()) {
                int x = Q.front().first;
                int y = Q.front().second;
                Q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == false) {
                        if (board[nx][ny] == board[x][y]) {
                            Q.push({ nx, ny });
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        fill(visited[i], visited[i] + n, false);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == false) cnt2++;
            Q.push({ i, j });
            visited[i][j] = true;
            while (!Q.empty()) {
                int x = Q.front().first;
                int y = Q.front().second;
                Q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == false) {
                        if (board[x][y] == 'B') {
                            if (board[nx][ny] == 'B') {
                                Q.push({ nx, ny });
                                visited[nx][ny] = true;
                            }
                        }
                        else {
                            if (board[nx][ny] != 'B') {
                                Q.push({ nx, ny });
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << cnt << ' ' << cnt2;
}