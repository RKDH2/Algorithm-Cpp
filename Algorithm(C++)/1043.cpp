#include <iostream>
using namespace std;

int parent[51];
int party[51][51];
int p_size[51];

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

void Union(int x, int y) {
    int rx, ry;
    rx = Find(x); ry = Find(y);
    if (rx != ry) {
        if (rx < ry) {
            parent[ry] = rx;
        }
        else {
            parent[rx] = ry;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int num;
    cin >> num;
    for (int i = 0; i <= n; ++i) {
        parent[i] = -1;
    }
    int tr;
    for (int i = 0; i < num; ++i) { // 진실
        cin >> tr;
        parent[tr] = 0;
    }
    for (int i = 0; i < m; ++i) {
        cin >> p_size[i];
        for (int j = 0; j < p_size[i]; ++j) {
            cin >> party[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= p_size[i] - 1; ++j) {
            Union(party[i][j], party[i][0]);
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        bool flag = true;
        for (int j = 0; j <= p_size[i] - 1; ++j) {
            if (Find(party[i][j]) == 0) {
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    }
    cout << ans;
}