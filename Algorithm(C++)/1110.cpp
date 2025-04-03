#include <iostream>

using namespace std;

int main() {
    int N, original, cycle = 0;
    cin >> N;
    original = N;

    do {
        int sum = ((N % 10) + (N / 10));
        N = (N % 10) * 10 + (sum % 10);
        cycle++;
    } while (N != original);

    cout << cycle;
    return 0;
}