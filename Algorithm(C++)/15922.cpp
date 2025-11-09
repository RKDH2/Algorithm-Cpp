#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x, y });
    }
    int prevX = v[0].first, prevY = v[0].second, ans = prevY - prevX;
    for (int i = 1; i < v.size(); i++) {
        auto line = v[i];
        int nextX = line.first;
        int nextY = line.second;
        if (prevY > nextX) {
            if (prevY < nextY) {
                ans += nextY - prevY;
                prevY = nextY;
            }
        }
        else {
            ans += nextY - nextX;
            prevX = nextX; prevY = nextY;
        }
    }
    cout << ans;
}