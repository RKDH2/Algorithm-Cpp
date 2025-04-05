#include <iostream>
#include <vector>

using namespace std;

int target, cnt = 0;
int root = -1;

vector<vector<int>> tree(51);

void traverse(int node) {
    if (target == node) {
        return;
    }
    int childCount = 0;
    for (auto child : tree[node]) {
        if (target == child)
            continue;
        childCount++;
    }
    if (childCount == 0) {
        cnt++;
        return;
    }

    for (auto child : tree[node]) {
        traverse(child);
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int parent;
        cin >> parent;
        if (parent == -1) {
            root = i;
            continue;
        }
        tree[parent].push_back(i);
    }
    cin >> target;

    traverse(root);
    cout << cnt;
}