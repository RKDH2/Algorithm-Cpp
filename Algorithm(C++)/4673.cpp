#include <iostream>
using namespace std;

int self_number(int num) {
    int rest = num;

    while (num != 0) {
        rest = rest + (num % 10);
        num = num / 10;
    }

    return rest;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool check_number[10001] = { false };

    for (int i = 1; i < 10001; ++i) {
        int n = self_number(i);

        if (n <= 10000) {
            check_number[n] = true;
        }
    }

    for (int i = 1; i < 10001; ++i) {
        if (!check_number[i]) {
            cout << i << "\n";
        }
    }
}