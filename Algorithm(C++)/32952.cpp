#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long R, K, M;
    cin >> R >> K >> M;

    long long step = K;
    int cnt = 0;

    while (cnt < M && R > 0) {
        long long nextStep = min(M, step);
        cnt = static_cast<int>(nextStep);
        R /= 2;
        step *= K;
    }

    cout << R << '\n';
    return 0;
}
