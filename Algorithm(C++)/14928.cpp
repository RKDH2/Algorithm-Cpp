#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string n;
    cin >> n;

    int total = 0;
    for (char num : n) {
        total = (total * 10 + (num - '0')) % 20000303;
    }

    cout << total;
}