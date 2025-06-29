#include <iostream>
#include <deque>
using namespace std;

int number[1001];

int main() {
    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> number[i];
        dq.push_back(i + 1);
    }
    while (!dq.empty()) {
        int ans = 0;
        ans = dq.front();
        cout << ans << ' ';
        dq.pop_front();
        int loop = number[ans - 1];
        if (loop > 0) {
            for (int i = 0; i < loop - 1; ++i) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            loop *= -1;
            for (int i = 0; i < loop; ++i) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}