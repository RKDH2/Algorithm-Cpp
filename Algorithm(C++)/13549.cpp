#include <iostream>
#include <queue>
using namespace std;

int line[100001];
bool visited[100001];

int main() {
    int n, k;
    cin >> n >> k;
    fill(line, line + 100001, 0);

    queue<int> Q;
    Q.push(n);
    line[n] = 0;
    visited[n] = true;
    while (!Q.empty()) {
        //큐에서 현재 위치 뽑기
        int loc = Q.front();
        Q.pop();
        //현재 위치 기준, 갈 수 있는 경우의 수 테스트
        int minus = loc - 1;
        int plus = loc + 1;
        int tel = 2 * loc;

        if (minus >= 0 && !visited[minus]) {
            visited[minus] = true;
            line[minus] = line[loc] + 1;
            Q.push(minus);
        }

        if (loc <= k) {
            if (tel < 100001 && !visited[tel]) {
                visited[tel] = true;
                line[tel] = line[loc];
                Q.push(tel);
            }
            if (plus <= k && !visited[plus]) {
                visited[plus] = true;
                line[plus] = line[loc] + 1;
                Q.push(plus);
            }
        }

    }
    cout << line[k];
}