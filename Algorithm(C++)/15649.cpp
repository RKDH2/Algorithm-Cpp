#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool visited[9];
vector<int> v;

void bk(int s) {
    if (v.size() == m) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
    }
    else {
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                v.push_back(i);
                visited[i] = true;
                bk(s + 1);
                v.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    bk(0);
}