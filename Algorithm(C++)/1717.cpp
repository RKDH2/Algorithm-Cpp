#include <iostream>
using namespace std;

int parent[1000001]; // 부모의 노드값을 나타낸다.

// 대표값 찾는 함수
int Find(int x) {
    if (parent[x] == -1) { // 부모의 노드값이 -1 일때 (-1은 더 이상의 부모가 없다는 뜻)
        return x;
    }
    else {
        int root = Find(parent[x]); // 부모(parent)의 부모(Find)를 찾는 코드 (재귀 함수로 대표값을 찾아온다.)
        parent[x] = root; // 자식과 대표값의 경로를 압축한다.
        return root; // 대표값을 반환해준다.
    }
}

// x가 포함된 집합이랑 y가 포함된 집합을 대상으로 합집합을 만들어주는 함수
void Union(int x, int y) {
    int rx, ry;
    rx = Find(x); ry = Find(y); // 대표값을 찾아온다.
    if (rx == ry) return;
    else { // 대표값이 서로 다르면
        parent[ry] = rx;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        parent[i] = -1; // 대표값이 나 자신임을 표시
    }
    for (int i = 0; i < m; ++i) {
        int z, a, b;
        cin >> z >> a >> b;
        if (z == 0) {
            Union(a, b); // 합집합을 만들어주는 함수 호출
        }
        else {
            if (Find(a) == Find(b)) { // 대표값이 같은면
                cout << "YES" << '\n';
            }
            else if (Find(a) != Find(b)) { // 대표값이 다르면
                cout << "NO" << '\n';
            }
        }
    }
}