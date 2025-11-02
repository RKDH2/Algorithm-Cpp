#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> e[101001]; // 하이퍼튜브 하나에 연결된 역을 받을 배열
bool visited[101001]; // 방문 여부를 확인

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) { // 하이퍼 튜브 개수 (m)
        vector<int> hpt(k);
        for (int j = 0; j < k; j++) { // 연결된 역 k개
            cin >> hpt[j];
            e[i + 100000 + 1].push_back(hpt[j]); // 하이퍼튜브 -> 역
            e[hpt[j]].push_back(i + 100000 + 1); // 역 -> 하이퍼튜브
        }
    }

    queue<pair<int, int>> q; // bfs
    q.push({ 1, 1 });
    visited[1] = true;
    while (!q.empty()) {
        int node = q.front().first; // 현재 역
        int dis = q.front().second; // 역까지의 방문 거리
        q.pop();
        if (node == n) { // n번역 도착
            cout << dis;
            return 0;
        }
        for (int i = 0; i < e[node].size(); i++) { // 현재 역과 연결된 역들
            int nextStation = e[node][i];
            if (!visited[nextStation]) { // 연결된 역들의 방문 여부 확인
                if (nextStation > 100000) // 다음 node가 하이퍼튜브라면
                    q.push({ nextStation, dis }); // 거리 증가 X (하이퍼튜브는 역이 아님)
                else { // 다음 노드가 역이라면
                    q.push({ nextStation, dis + 1 }); // 거리 증가 O
                }
                visited[nextStation] = true; // bfs는 q에 push할 때 방문처리 (나올 때 방문 처리 X)
            }
        }
    }
    if (!visited[n]) // 목표 역이 방문 하지 못할 경우
        cout << -1;
}