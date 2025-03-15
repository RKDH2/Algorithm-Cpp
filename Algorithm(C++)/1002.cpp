#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int radius_sum = r1 + r2;
        int radius_sub = abs(r1 - r2);
        double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
        if (x1 == x2 && y1 == y2 && r1 == r2) {
            cout << -1 << '\n';
        }
        else if (distance <= radius_sub) {
            if (distance == radius_sub) {
                cout << 1 << '\n';
            }
            else if (distance < radius_sub) {
                cout << 0 << '\n';
            }
        }
        else if (distance >= radius_sum) {
            if (distance == radius_sum) {
                cout << 1 << '\n';
            }
            else if (distance > radius_sum) {
                cout << 0 << '\n';
            }
        }
        else if (distance > radius_sub || distance < radius_sum) {
            cout << 2 << '\n';
        }
    }
}