#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string board[12];
bool visited[12][6];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int cnt = 0;

bool Bfs() {
    bool flag = false; fill_n(&visited[0][0], 6 * 12, false);
    for (int i = 11; i >= 0; i--) {
        for (int j = 0; j < 6; j++) {
            if (visited[i][j] == true) continue;
            if (board[i][j] == '.') continue;
            queue<pair<int, int>> puyo;
            puyo.push({ i, j });
            visited[i][j] = true;
            vector<pair<int, int>> temp;
            temp.push_back({ i, j });
            while (!puyo.empty()) {
                auto loc = puyo.front();
                int x = loc.first;
                int y = loc.second;
                puyo.pop();
                for (int q = 0; q < 4; q++) {
                    int nx = dx[q] + x;
                    int ny = dy[q] + y;
                    if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
                    if (visited[nx][ny] == true) continue;
                    if (board[nx][ny] == '.') continue;
                    if (board[x][y] != board[nx][ny]) continue;
                    visited[nx][ny] = true;
                    temp.push_back({ nx, ny });
                    puyo.push({ nx, ny });
                }
            }
            if (temp.size() >= 4) {
                for (auto nv : temp) {
                    board[nv.first][nv.second] = '.';
                }
                flag = true;
            }
        }
    }
    return flag;
}

void DownPuyo() {
    vector<char> temp;
    for (int i = 0; i < 6; i++) {
        for (int j = 11; j >= 0; j--) {
            if (board[j][i] != '.') {
                temp.push_back(board[j][i]);
            }
        }
        for (int j = 11; j > 11 - (int)temp.size(); j--) {
            board[j][i] = temp[11 - j];
        }
        for (int j = 0; j <= 11 - (int)temp.size(); j++) {
            board[j][i] = '.';
        }
        temp.clear();
    }
}

int main() {
    for (int i = 0; i < 12; i++) {
        cin >> board[i];
    }
    int cnt = 0;
    while (Bfs()) {
        cnt++;
        DownPuyo();
    }
    cout << cnt;
}