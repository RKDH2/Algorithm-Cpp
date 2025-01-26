#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

bool visited[51][51];
int map[51][51];

int dx[] = { 0,0,1,-1 }; // 가로, 1 오른, -1 왼
int dy[] = { 1,-1,0,0 }; // 세로
int cnt = 0;

int T, M, N, K;

void dfs(int curx, int cury) {
    visited[curx][cury] = true;
    for (int i = 0; i < 4; ++i) {
        int nextx = curx + dx[i];
        int nexty = cury + dy[i];
        if (nextx < 51 && nexty < 51 && nextx >= 0 && nexty >= 0) {
            if (map[nextx][nexty] == 1 && !visited[nextx][nexty])
                dfs(nextx, nexty);
        }
    }
}

int main() {
    // 가로 M, 세로 N
    cin >> T;

    for (int i = 0; i < T; ++i) {
        vector<pii> bc;
        cin >> M >> N >> K;
        for (int j = 0; j < K; ++j) {
            int x, y;
            cin >> x >> y;
            bc.push_back({ x, y });
            map[x][y] = 1;
        }
        cnt = 0;
        for (auto BC : bc) {
            if (!visited[BC.first][BC.second]) {
                cnt++;
                dfs(BC.first, BC.second);
            }
        }
        cout << cnt << "\n";
        for (int a = 0; a < 51; ++a) {
            for (int b = 0; b < 51; ++b) {
                map[a][b] = 0;
                visited[a][b] = false;
            }
        }
    }
}