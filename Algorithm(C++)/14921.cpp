#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int const INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> potion(n);
    for (int i = 0; i < n; i++) {
        cin >> potion[i];
    }
    int target = INF;
    int st = 0, ed = n - 1;
    while (st < ed) {
        int tmp = potion[st] + potion[ed];

        if (abs(tmp) < abs(target)) {
            target = tmp;
        }
        if (tmp < 0) {
            st++;
        }
        else if (tmp > 0) {
            ed--;
        }
        else {
            cout << target;
            return 0;
        }
    }

    cout << target;
}