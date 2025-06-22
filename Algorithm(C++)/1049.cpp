#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int setMin = 1001, each = 1001;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (setMin > a) {
            setMin = a;
        }
        if (each > b) {
            each = b;
        }
    }
    int c1 = each * n;
    int nn = n / 6;
    if (n % 6 != 0) nn += 1;
    int c2 = nn * setMin;
    int c3 = (n / 6) * setMin + (n % 6) * each;
    int result = min({ c1, c2, c3 });
    cout << result;
}