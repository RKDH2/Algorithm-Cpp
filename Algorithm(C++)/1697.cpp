#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];

int main() {
    int n, k;
    cin >> n >> k;
    queue<pair<int, int>> Q;
    Q.push({ n, 0 });
    visited[n] = true;
    while (!Q.empty()) {
        int cur_node = Q.front().first;
        int cur_dis = Q.front().second;
        Q.pop();
        if (cur_node == k) {
            cout << cur_dis;
            break;
        }
        int next1 = cur_node - 1;
        int next2 = cur_node + 1;
        int next3 = cur_node * 2;
        if (next1 >= 0 && next1 <= 100000 && !visited[next1]) {
            visited[next1] = true;
            Q.push({ next1, cur_dis + 1 });
        }
        if (next2 >= 0 && next2 <= 100000 && !visited[next2]) {
            visited[next2] = true;
            Q.push({ next2, cur_dis + 1 });
        }
        if (next3 >= 0 && next3 <= 100000 && !visited[next3]) {
            visited[next3] = true;
            Q.push({ next3, cur_dis + 1 });
        }
    }
}