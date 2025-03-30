#include <iostream>
#include <vector>

using namespace std;

vector<int> edge[100001];
int parent[100001];

void tree(int p) {
    for (auto c : edge[p]) {
        if (parent[p] != c) {
            parent[c] = p;
            if (1 != edge[c].size()) {
                tree(c);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i) {
        int pn1, pn2;
        cin >> pn1 >> pn2;
        edge[pn1].push_back(pn2);
        edge[pn2].push_back(pn1);
    }

    tree(1);

    for (int i = 2; i <= N; ++i) {
        cout << parent[i] << '\n';
    }
}