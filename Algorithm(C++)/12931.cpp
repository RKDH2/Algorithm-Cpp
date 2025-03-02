#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> B;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        B.push_back(n);
    }
    int cnt = 0;
    while (1) {
        for (int& n : B) {
            if (n % 2 == 1) {
                n -= 1;
                cnt++;
            }
        }

        bool flag = true;
        for (int& n : B) {
            if (n) // n != 0
                flag = false;
        }
        if (flag) {
            break;
        }

        for (int& n : B) {
            n /= 2;
        }
        cnt++;
    }
    printf("%d", cnt);
}