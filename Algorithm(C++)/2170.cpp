#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) return true;
    else if (a.first > b.first) return false;
    if (a.second < b.second) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x, y });
    }
    sort(v.begin(), v.end(), cmp);
    int prevX = v[0].first, prevY = v[0].second, ans = prevY - prevX;
    for (int i = 1; i < v.size(); i++) {
        auto line = v[i];
        int nextX = line.first;
        int nextY = line.second;
		if (prevY > nextX) { // 겹치는 부분이 있는 경우
			if (prevY < nextY) { // 완전 겹치지 않는 경우
                ans += nextY - prevY;
                prevY = nextY;
            }
        }
		else { // 겹치는 부분이 없는 경우
            ans += nextY - nextX;
            prevX = nextX; prevY = nextY;
        }
    }

    cout << ans;
}