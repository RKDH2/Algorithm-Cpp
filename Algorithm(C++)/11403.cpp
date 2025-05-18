#include <iostream>
using namespace std;

int main() {
    const int INF = 0x3f3f3f3f;
    int n; cin >> n;
    int graph[101][101];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < n; ++i) graph[i][i] = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][k] + graph[k][j] == 2) {
                    graph[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == 0) {
                cout << 0 << ' ';
            }
            else {
                cout << 1 << ' ';
            }
        }
        cout << '\n';
    }
}