#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> v(N);
        for (int j = 0; j < N; ++j) {
            cin >> v[j].first >> v[j].second;
        }
        sort(v.begin(), v.end());
        int cnt = 0, best = v[0].second;
        for (int i = 0; i < (int)v.size(); ++i) {
            if (v[i].second <= best) {
                cnt++;
                best = v[i].second;
            }
        }
        cout << cnt << '\n';
    }
}