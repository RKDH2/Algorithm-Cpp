#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, total = 0;
    cin >> n;

    vector<int> village(n);
    for (int i = 0; i < n; ++i) {
        cin >> village[i];
    }

    sort(village.begin(), village.end());

    for (int i = 0; i < n - 1; ++i) {
        total += village[i];
    }

    cout << total << "\n";
}