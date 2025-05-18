#include<iostream>
#include<queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        priority_queue<long long, vector<long long>, greater<long long>> files;
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int num;
            cin >> num;
            files.push(num);
        }
        long long add = 0;
        while (files.size() > 1) {
            long long f1 = files.top();
            files.pop();
            long long f2 = files.top();
            files.pop();
            add += (f1 + f2);
            files.push(f1 + f2);
        }
        cout << add << '\n';
    }
}