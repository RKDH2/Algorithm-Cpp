#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, cnt = 0;
    cin >> a >> b;
    while (0 < b) {
        if (b % 2 == 0) b /= 2;
        else if (b % 10 == 1) {
            b -= 1;
            b /= 10;
        }
        else {
            cout << -1;
            return 0;
        }
        cnt++;
        if (a == b) {
            cnt++;
            cout << cnt;
            return 0;
        }
    }
    cout << -1;
}