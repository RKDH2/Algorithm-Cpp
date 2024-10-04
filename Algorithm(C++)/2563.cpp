#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(NULL); // 입출력 속도 최적화

    int n, x, y, extent = 0;
    bool paper[100][100] = { false };
    cin >> n;

    while (n--) {
        cin >> x >> y;
        for (int i = y; i < y + 10; ++i) {
            for (int j = x; j < x + 10; ++j) {
                if (!paper[i][j]) {
                    extent++;
                    paper[i][j] = true;
                }
            }
        }
    }
    cout << extent << endl;
}