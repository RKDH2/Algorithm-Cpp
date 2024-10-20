#include <iostream>
using namespace std;

char w[51][51];

int w_b_search(int x, int y) {
    int cntW = 0;
    int cntB = 0;
    for (int i = x; i < x + 8; ++i) {
        for (int j = y; j < y + 8; ++j) {
            if (w[i][j] == 'W' && (i + j) % 2 == 1) {
                cntW++;
            }
            if (w[i][j] == 'B' && (i + j) % 2 == 0) {
                cntW++;
            }

            if (w[i][j] == 'B' && (i + j) % 2 == 1) {
                cntB++;
            }
            if (w[i][j] == 'W' && (i + j) % 2 == 0) {
                cntB++;
            }
        }
    }

    return min(cntW, cntB);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> w[i][j];
        }
    }

    int ans = 65;
    for (int i = 0; i + 8 <= n; ++i) {
        for (int j = 0; j + 8 <= m; ++j) {
            int wb_min = w_b_search(i, j);
            if (wb_min < ans) ans = wb_min;
        }
    }

    cout << ans;
}