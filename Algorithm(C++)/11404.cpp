#include <iostream>

using namespace std;

const int INF = 0x33f3f3f3;
int board[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fill(board[i], board[i] + n + 1, INF);
    }

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] = min(board[a][b], c);
    }
    for (int i = 1; i <= n; ++i) board[i][i] = 0;

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (board[i][j] == INF)
                board[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}