#include <iostream>
#include <queue>

using namespace std;

typedef pair<pair<int, int>, int> piii;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int cnt = 0;
int map[1001][1001];

int M, N;

int main() {
    queue<piii> to;

    cin >> M >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int TO;
            cin >> TO;
            map[i][j] = TO;
            if (TO == 1) // 익은 상태
                to.push({ {i, j}, 0 }); // (i,j)위치의 토마토는 0일 뒤에 익음
        }
    }

    int maxDay = 0;

    while (!to.empty()) {
        int curx = to.front().first.first;
        int cury = to.front().first.second;
        int curday = to.front().second;
        maxDay = maxDay > curday ? maxDay : curday;
        to.pop();

        for (int i = 0; i < 4; ++i) {
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];
            if (nextx < N && nexty < M && nextx >= 0 && nexty >= 0) {
                if (map[nextx][nexty] == 0) {
                    to.push({ {nextx, nexty}, curday + 1 });
                    map[nextx][nexty] = 1;
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == 0) {
                cout << "-1";
                return 0;
            }
        }
    }

    cout << maxDay;
}