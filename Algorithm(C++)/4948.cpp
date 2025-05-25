#include <iostream>
using namespace std;
const int MAX = 123457 * 2;
int arr[MAX] = { 0, };

int main() {
    arr[1] = 1;
    for (int i = 2; i < MAX; ++i) {
        if (arr[i] == 1) {
            continue;
        }
        for (int j = i * 2; j < MAX; j = j + i) {
            arr[j] = 1;
        }
    }


    while (true) {
        int num;
        cin >> num;
        if (num == 0) return 0;
        int cnt = 0;
        for (int i = num + 1; i <= num * 2; ++i) {
            if (arr[i] == 0) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}