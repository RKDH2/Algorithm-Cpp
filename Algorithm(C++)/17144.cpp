#include <iostream>
#include <tuple>
using namespace std;

int board[51][51];
int delta[51][51];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    int r, c, t;
    cin >> r >> c >> t;
    int loct = -1, locb = -1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) {
                if (loct == -1) {
                    loct = i;
                }
                else {
                    locb = i;
                }
            }
        }
    }
    while (t--) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] <= 4) continue;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];


                    if (nx < r && ny < c && nx >= 0 && ny >= 0) {

                        if (board[nx][ny] == -1) continue;

                        int tmp = board[i][j] / 5;
                        delta[i][j] -= tmp;
                        delta[nx][ny] += tmp;
                    }
                }
            }
        }
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                board[i][j] += delta[i][j];
                delta[i][j] = 0;
            }

        // loct
        for (int i = loct - 2; i >= 0; i--) {
            board[i + 1][0] = board[i][0];
        }
        for (int i = 0; i <= c - 2; i++) {
            board[0][i] = board[0][i + 1];
        }
        for (int i = 0; i <= loct - 1; i++) {
            board[i][c - 1] = board[i + 1][c - 1];
        }
        for (int i = c - 1; i >= 2; i--) {
            board[loct][i] = board[loct][i - 1];
        }
        board[loct][1] = 0;
        // locb
        for (int i = locb + 2; i <= r - 1; i++) {
            board[i - 1][0] = board[i][0];
        }
        for (int i = 0; i <= c - 2; i++) {
            board[r - 1][i] = board[r - 1][i + 1];
        }
        for (int i = r - 2; i >= locb; i--) {
            board[i + 1][c - 1] = board[i][c - 1];
        }
        for (int i = c - 1; i >= 2; i--) {
            board[locb][i] = board[locb][i - 1];
        }
        board[locb][1] = 0;
    }
    int result = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == -1) continue;
            result += board[i][j];
        }
    }
    cout << result;
}