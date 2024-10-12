#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int num1 = min(x, y);
    int num2 = min(w - x, h - y);
    int temp = min(num1, num2);

    cout << temp << '\n';
}