#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> sensor;

int main() {
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        sensor.push_back(tmp);
    }
    sort(sensor.begin(), sensor.end());
    for (int i = 0; i < n - 1; ++i) {
        if (sensor[i + 1] - sensor[i] != 0) pq.push(sensor[i + 1] - sensor[i]);
    }
    for (int i = 0; i < k - 1; ++i) {
        if (!pq.empty()) pq.pop();
    }
    int result = 0;
    while (!pq.empty()) {
        result += pq.top();
        pq.pop();
    }
    cout << result;
}