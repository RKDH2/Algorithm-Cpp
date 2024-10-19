#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, num1, num2;
    cin >> n;
    vector<int> vec1;
    for (int i = 0; i < n; ++i) {
        cin >> num1;
        vec1.push_back(num1);
    }
    cin >> m;
    vector<int> vec2;
    for (int i = 0; i < m; ++i) {
        cin >> num2;
        vec2.push_back(num2);
    }

    sort(vec1.begin(), vec1.end());
    for (int v : vec2) {
        auto it1 = upper_bound(vec1.begin(), vec1.end(), v);
        auto it2 = lower_bound(vec1.begin(), vec1.end(), v);
        int nu = it1 - it2;
        cout << nu << " ";
    }
}