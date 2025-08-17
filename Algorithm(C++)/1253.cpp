#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> good;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        good.push_back(t);
    }
    sort(good.begin(), good.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int st = 0, ed = n - 1;
        int target = good[i];
        while (st < ed) {
            if (i == st) {
                st++;
                continue;
            }
            if (i == ed) {
                ed--;
                continue;
            }

            int tmp = good[st] + good[ed];
            if (tmp == target) {
                cnt++;
                break;
            }
            if (tmp < target) {
                st++;
            }
            if (tmp > target) {
                ed--;
            }
        }
    }
    cout << cnt;
}