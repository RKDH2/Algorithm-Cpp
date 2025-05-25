#include <iostream>
#include <vector>
using namespace std;

int arr[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    arr[1] = 1;
    for (int i = 2; i < 10001; ++i) {
        if (arr[i] == 1) continue;
        for (int j = i * 2; j < 10001; j = j + i) {
            arr[j] = 1;
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        vector<int> vc;
        for (int t = 2; t < num; ++t) {
            if (arr[t] == 0)
                vc.push_back(t);
        }
        int a, b;
        for (int t = 0; t < vc.size(); ++t) {
            for (int j = t; j < vc.size(); ++j) {
                if (vc[t] + vc[j] == num) {
                    a = vc[t];
                    b = vc[j];
                }
            }
        }
        cout << a << ' ' << b << '\n';
    }
}