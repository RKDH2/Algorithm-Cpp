#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, less<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (i == 0) {
            pq1.push(num);
        }
        else if (pq1.size() > pq2.size()) {
            if (pq1.top() < num) {
                pq2.push(num);
            }
            else {
                int tmp = pq1.top();
                pq1.pop();
                pq2.push(tmp);
                pq1.push(num);
            }
        }
        else if (pq1.size() == pq2.size()) {
            if (pq1.top() > num || pq2.top() > num) {
                pq1.push(num);
            }
            else {
                int tmp = pq2.top();
                pq2.pop();
                pq1.push(tmp);
                pq2.push(num);
            }
        }
        cout << pq1.top() << '\n';
    }
}