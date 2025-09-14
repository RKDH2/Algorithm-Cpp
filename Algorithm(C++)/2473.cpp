#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e10;

int main() {
    int n;
    cin >> n;
    vector<long long> potion(n);
    vector<long long> po_box;
    for (int i = 0; i < n; i++) {
        cin >> potion[i];
    }
    sort(potion.begin(), potion.end());
    long long po1 = INF, po2 = INF, po3 = INF;
    long long target = INF;
    for (int i = 0; i < n; i++) {
        int st = 0, ed = n - 1;
        while (st < ed) {
            if (i == st) {
                st++;
                continue;
            }
            if (i == ed) {
                ed--;
                continue;
            }
            long long box = potion[i];
            long long tmp = potion[st] + potion[ed] + box;

            if (abs(tmp) < abs(target)) {
                po_box.clear();
                po_box.push_back(potion[st]);
                po_box.push_back(potion[ed]);
                po_box.push_back(box);
                sort(po_box.begin(), po_box.end());
                target = tmp;
            }
            if (tmp < 0) {
                st++;
            }
            else if (tmp > 0) {
                ed--;
            }
            else {
                for (auto nv : po_box) {
                    cout << nv << ' ';
                }
                return 0;
            }
        }
    }
    for (auto nv : po_box) {
        cout << nv << ' ';
    }
}