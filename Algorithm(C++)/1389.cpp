#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x33f3f3f3;
int board[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, cnt = 0;
    vector<pair<int, int>> vc;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        fill(board[i], board[i] + N + 1, INF);
    }
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
        board[b][a] = 1;
    }
    for (int i = 1; i <= N; ++i) board[i][i] = 0;
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cnt += board[i][j];
        }
        vc.push_back({ cnt, i });
        cnt = 0;
    }
    sort(vc.begin(), vc.end());
    cout << vc[0].second;
}