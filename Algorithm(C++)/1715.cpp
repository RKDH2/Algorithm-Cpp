#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;

    int n, num, total = 0;
    cin >> n;


    for (int i = 0; i < n; ++i) {
        cin >> num;
        pq.push(num);
    }

    while (!pq.empty()) {
        int first = pq.top();
        pq.pop();
        if (pq.empty()) break;
        int second = pq.top();
        pq.pop();
        int sum = first + second;
        total += sum;
        pq.push(sum);
    }

    cout << total;
}