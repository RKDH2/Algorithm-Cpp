#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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
    int st = 0, ed = n - 1;
    int target = INF;
    while (st < ed) {
        int tmp = potion[st] + potion[ed];


        if (abs(tmp) < abs(target)) {
            target = tmp;
            po1 = potion[st]; po2 = potion[ed];

            if (tmp == 0) {
                break;
            }
        }

        if (tmp <= 0) {
            st++;
        }
        if (tmp > 0) {
            ed--;
        }

    }
    cout << po1 << " " << po2 << '\n';
}