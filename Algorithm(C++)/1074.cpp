#include <iostream>

using namespace std;

int Solution(int N, int r, int c, int result) {
    int side = 1 << N;
    int num = result;
    if (r >= side / 2) {
        num += side * side / 2;
        r -= side / 2;
    }
    if (c >= side / 2) {
        num += side * side / 4;
        c -= side / 2;
    }
    if (side == 2) {
        return num;
    }
    return Solution(N - 1, r, c, num);
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;

    cout << Solution(N, r, c, 0);
}