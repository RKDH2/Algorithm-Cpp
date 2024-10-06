#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double diameter, distance, second, MPH; int rotation, count = 1;

    while (true) {
        cin >> diameter >> rotation >> second;
        if (rotation == 0) break;

        distance = ((1.0 / 12) * (1.0 / 5280)) * diameter; // 지름(인치->마일)
        distance = distance * 3.1415927; // 원의 둘레
        distance = distance * rotation; // 총 거리

        MPH = distance / ((second * (1.0 / 3600)));

        cout << fixed;
        cout.precision(2);
        cout << "Trip #" << count << ": " << distance << " " << MPH << "\n";
        count++;
    }
}