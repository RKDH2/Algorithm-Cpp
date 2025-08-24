#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vc;
    for (int i = 0; i < n; i++) {
        int st, ed;
        cin >> st >> ed;
        vc.push_back({ st, ed });
    }
    sort(vc.begin(), vc.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    auto room = vc[0];
    pq.push(room.second);
    for (int i = 1; i < n; i++) {
        int ed_time = pq.top();
        int rtf = vc[i].first;
        int rts = vc[i].second;
        if (rtf >= ed_time) {
            pq.pop();
            pq.push(rts);
        }
        else {
            pq.push(rts);
        }
    }
    cout << pq.size();
}