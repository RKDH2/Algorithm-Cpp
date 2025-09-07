#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

int main() {
    int n;
    cin >> n;
    vector<int> potion(n);
    for (int i = 0; i < n; i++) {
        cin >> potion[i];
    }
    sort(potion.begin(), potion.end());
    int po1 = INF, po2 = INF;
    int target = INF;
    int st = 0, ed = n - 1;
    while (st < ed) {
        int tmp = potion[st] + potion[ed];

        if (abs(tmp) < abs(target)) {
            po1 = potion[st];
            po2 = potion[ed];
            target = tmp;
        }
        if (tmp < 0) {
            st++;
        }
        else if (tmp > 0) {
            ed--;
        }
        else {
            cout << po1 << ' ' << po2;
            return 0;
        }
    }

    cout << po1 << ' ' << po2;
}