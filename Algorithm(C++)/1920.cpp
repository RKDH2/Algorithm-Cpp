#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, num1, num2;
    vector<int> vec1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num1;
        vec1.push_back(num1);
    }
    sort(vec1.begin(), vec1.end());
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int key;
        cin >> key;
        bool flag = false;
        int st = 0;
        int ed = vec1.size() - 1;
        while (st <= ed) {
            auto mid = (st + ed) / 2;
            if (vec1[mid] == key) {
                flag = true;
                break;
            }
            else if (vec1[mid] > key) ed = mid - 1;
            else st = mid + 1;
        }

        if (flag) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    

}