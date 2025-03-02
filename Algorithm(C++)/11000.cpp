#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare1(pair<int, int> a, pair<int, int> b) {
    if (b.first == a.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), compare1);
    priority_queue<int, vector<int>, greater<>> pq;

    pq.push(v[0].second);
    for (int i = 1; i < v.size(); ++i) {
        if (pq.top() <= v[i].first) {
            pq.pop();
            pq.push(v[i].second);
        }
        else {
            pq.push(v[i].second);
        }
    }
    cout << pq.size();
}