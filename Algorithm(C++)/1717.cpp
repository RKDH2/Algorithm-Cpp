#include <iostream>
using namespace std;

int parent[1000001]; // �θ��� ��尪�� ��Ÿ����.

// ��ǥ�� ã�� �Լ�
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

// x�� ���Ե� �����̶� y�� ���Ե� ������ ������� �������� ������ִ� �Լ�
void Union(int x, int y) {
    int rx, ry;
    rx = Find(x); ry = Find(y); // ��ǥ���� ã�ƿ´�.
    if (rx == ry) return;
    else { // ��ǥ���� ���� �ٸ���
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
        parent[i] = -1; // ��ǥ���� �� �ڽ����� ǥ��
    }
    for (int i = 0; i < m; ++i) {
        int z, a, b;
        cin >> z >> a >> b;
        if (z == 0) {
            Union(a, b); // �������� ������ִ� �Լ� ȣ��
        }
        else {
            if (Find(a) == Find(b)) { // ��ǥ���� ������
                cout << "YES" << '\n';
            }
            else if (Find(a) != Find(b)) { // ��ǥ���� �ٸ���
                cout << "NO" << '\n';
            }
        }
    }
}