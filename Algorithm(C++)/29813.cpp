#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    queue<pair<string, int>> q;
    for (int i = 0; i < n; i++) {
        string initial;
        int num;
        cin >> initial >> num;
        q.push({ initial, num });
    }
    while (q.size() > 1) {
        int tmp = q.front().second; q.pop();
        tmp = tmp % q.size();
        if (tmp == 0) tmp = q.size();
        for (int i = 0; i < tmp - 1; i++) {
            auto box = q.front();
            q.pop();
            q.push(box);
        }
        q.pop();
    }

    cout << q.front().first;
}