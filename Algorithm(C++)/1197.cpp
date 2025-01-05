#include <iostream>
#include <queue>

using namespace std;

int parent[10001];
int s[10001];

typedef pair<int, pair<int, int>> piii;

int Find(int x) { // ��) 5 -> 0 -> 2 (�θ� ��)
    if (parent[x] == -1) { // parent[parent[5]] -> parent[parent[5] -> 0 �̱� ����] -> parent[0]
        return x;
    }
    else {
        int root = Find(parent[x]); // x = parent[5] <- �̷� �������� x�� ��͵�. (1�� �ڵ�)
        parent[x] = root; // (2�� �ڵ�) ��� ���� �ڵ�.
        return root; // (3�� �ڵ�)�� ������ 2���� ���� ��ȯ�� �ȴ�.
        // ���� �Լ��� ������ Find(5)�� ������ Find(0) -> Find(2) ������ ���ƿ��鼭 ���� �ڵ带 ����.
        // ���� �Լ� �ڵ尡 ������ 2���� ���� ��ȯ�� �ȴ�.
    }
}

void Union(int x, int y) {
    int rx, ry;
    rx = Find(x); ry = Find(y);
    if (rx != ry) {
        if (s[rx] < s[ry]) {
            parent[rx] = ry; // ��) parent[3] = 4
            s[ry] += s[rx]; // 4�� ������ += 3�� ����� �ִ´�.
        }
        else {
            parent[ry] = rx;
            s[rx] += s[ry];
        }
    }
}

int main() {
    int total = 0;
    // ��) vector(���ø� Ŭ����), greater(���ø� �Լ�) ���� ����, <�ڷ���> -> Ÿ�� ����(���)
    priority_queue<piii, vector<piii>, greater<piii>> tree; // ��) piii �������� ���� (fisrt ����)
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