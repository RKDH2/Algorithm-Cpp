#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 0x33f3f3f3;
int board[101][101];
int item[101];
int cnt[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, r, t;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> item[i];
    }
    for (int i = 1; i <= n; ++i) {
        fill(board[i], board[i] + n + 1, INF);
    }
    for (int i = 0; i < r; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        board[a][b] = l;
        board[b][a] = l;
    }
    for (int i = 1; i <= n; ++i) board[i][i] = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (board[i][j] <= m) {
                cnt[i] += item[j];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] > cnt[ans]) {
            ans = i;
        }
    }
    cout << cnt[ans];
}