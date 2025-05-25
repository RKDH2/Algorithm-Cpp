#include <iostream>
using namespace std;

int arr[1001];

int main() {
    int n, k, cnt = 0;

    cin >> n >> k;
    arr[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (arr[i] == 1) {
            continue;
        }
        for (int j = i; j <= n; j = j + i) {
            if (arr[j] == 0) {
                arr[j] = 1;
                cnt++;
                if (cnt == k) {
                    cout << j;
                    return 0;
                }
            }
        }
    }
}