#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
int board[101][101];
int nx[101][101] = { 0 };

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
        nx[a][b] = b;
    }
    for (int i = 1; i <= n; ++i) board[i][i] = 0;

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (board[i][j] > board[i][k] + board[k][j]) {
                    board[i][j] = board[i][k] + board[k][j];
                    nx[i][j] = nx[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (board[i][j] == INF) {
                cout << 0 << ' ';
            }
            else {
                cout << board[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (nx[i][j] == 0) {
                cout << 0 << '\n';
            }
            else {
                vector<int> tree;
                int nextStart = i;
                while (nextStart != j) {
                    tree.push_back(nextStart);
                    nextStart = nx[nextStart][j];
                }
                tree.push_back(j);
                cout << tree.size() << ' ';
                for (auto t : tree)
                    cout << t << ' ';
                cout << '\n';
            }
        }
    }
}