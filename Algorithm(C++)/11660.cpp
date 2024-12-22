#include <iostream>

using namespace std;

const int MAX = 2025;

int graph[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, num;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> num;
            graph[i][j] = graph[i - 1][j] + graph[i][j - 1] - graph[i - 1][j - 1] + num;
        }
    }
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << graph[x2][y2] - graph[x2][y1 - 1] - graph[x1 - 1][y2] + graph[x1 - 1][y1 - 1] << '\n';
    }
}