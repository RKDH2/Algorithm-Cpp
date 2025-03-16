#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int map[9][9];
int main_map[9][9];

int max_cnt = 0;

int main() {
    queue<pii> bloc;
    vector<pair<int, int>> v;

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int Bloc;
            cin >> Bloc;
            main_map[i][j] = Bloc;
            if (main_map[i][j] == 0) {
                v.push_back({ i, j });
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            for (int k = j + 1; k < v.size(); k++) {
                // map 복사
                for (int ii = 0; ii < N; ii++) {
                    for (int jj = 0; jj < M; jj++) {
                        map[ii][jj] = main_map[ii][jj];
                        if (main_map[ii][jj] == 2)
                            bloc.push({ ii, jj });
                    }
                }

                // 벽 세우기
                map[v[i].first][v[i].second] = 1;
                map[v[j].first][v[j].second] = 1;
                map[v[k].first][v[k].second] = 1;

                // 바이러스 퍼트리기
                while (!bloc.empty()) {
                    int curx = bloc.front().first;
                    int cury = bloc.front().second;
                    bloc.pop();

                    for (int i = 0; i < 4; ++i) {
                        int nextx = curx + dx[i];
                        int nexty = cury + dy[i];
                        if (nextx < N && nexty < M && nextx >= 0 && nexty >= 0) {
                            if (map[nextx][nexty] == 0) {
                                map[nextx][nexty] = 2;
                                bloc.push({ nextx, nexty });
                            }
                        }
                    }
                }

                // 안전 영역 계산
                int cnt = 0;
                for (int ii = 0; ii < N; ++ii) {
                    for (int jj = 0; jj < M; ++jj) {
                        if (map[ii][jj] == 0) {
                            cnt++;
                        }
                    }
                }
                if (max_cnt <= cnt) {
                    max_cnt = cnt;
                }
            }
        }
    }
    cout << max_cnt;
}