#include <iostream>
#include <queue>

using namespace std;

int parent[10001];
int s[10001];

typedef pair<int, pair<int, int>> piii;

int Find(int x) { // 예) 5 -> 0 -> 2 (부모 순)
    if (parent[x] == -1) { // parent[parent[5]] -> parent[parent[5] -> 0 이기 때문] -> parent[0]
        return x;
    }
    else {
        int root = Find(parent[x]); // x = parent[5] <- 이런 형식으로 x에 재귀됨. (1번 코드)
        parent[x] = root; // (2번 코드) 경로 압축 코드.
        return root; // (3번 코드)가 끝나면 2값이 최종 반환이 된다.
        // 현재 함수가 끝나고 Find(5)가 끝나면 Find(0) -> Find(2) 순으로 돌아오면서 남은 코드를 진행.
        // 남은 함수 코드가 끝나면 2값이 최종 반환이 된다.
    }
}

void Union(int x, int y) {
    int rx, ry;
    rx = Find(x); ry = Find(y);
    if (rx != ry) {
        if (s[rx] < s[ry]) {
            parent[rx] = ry; // 예) parent[3] = 4
            s[ry] += s[rx]; // 4의 사이즈 += 3의 사이즈를 넣는다.
        }
        else {
            parent[ry] = rx;
            s[rx] += s[ry];
        }
    }
}

int main() {
    int total = 0;
    // 예) vector(템플릿 클래스), greater(템플릿 함수) 구조 역할, <자료형> -> 타입 지정(명시)
    priority_queue<piii, vector<piii>, greater<piii>> tree; // 예) piii 오름차순 정렬 (fisrt 기준)
    int V, E;
    cin >> V >> E;
    int A, B, C;
    for (int i = 0; i <= V; ++i) {
        parent[i] = -1;
        s[i] = 1;
    }
    for (int i = 0; i < E; ++i) {
        cin >> A >> B >> C;
        tree.push({ C, {A, B} });
    }
    while (!tree.empty()) {
        int v1 = tree.top().second.first;
        int v2 = tree.top().second.second;
        int e = tree.top().first;

        tree.pop();
        if (Find(v1) != Find(v2)) {
            Union(v1, v2);
            total += e;
        }
    }

    cout << total;
}