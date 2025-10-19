#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d; // µ∑, ±‚«—
        v.push_back({ d, p }); // ±‚«—, µ∑
    }

    sort(v.begin(), v.end());
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        pq.push(v[i].second);
        if (v[i].first < pq.size()) {
            pq.pop();
        }
    }
    while (!pq.empty()) {
        int tmp = pq.top();
        pq.pop();
        res += tmp;
    }
    cout << res;
}