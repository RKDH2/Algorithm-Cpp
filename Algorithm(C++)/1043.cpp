#include <iostream>
using namespace std;

int parent[51];
int party[51][51];
int p_size[51];

int Find(int x) {
    if (parent[x] == -1) { // �θ��� ��尪�� -1 �϶� (-1�� �� �̻��� �θ� ���ٴ� ��)
        return x;
    }
    else {
        int root = Find(parent[x]); // �θ�(parent)�� �θ�(Find)�� ã�� �ڵ� (��� �Լ��� ��ǥ���� ã�ƿ´�.)
        parent[x] = root; // �ڽİ� ��ǥ���� ��θ� �����Ѵ�.
        return root; // ��ǥ���� ��ȯ���ش�.
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
    for (int i = 0; i < num; ++i) { // ����
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