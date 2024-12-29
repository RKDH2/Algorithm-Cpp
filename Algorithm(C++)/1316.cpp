#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, result;
    cin >> N;

    result = N;

    for (int i = 0; i < N; ++i) {
        bool ck[26] = { false, };

        string word;
        cin >> word;

        for (auto s : word) {
            int n = s - 'a';
            char w;
            if (!ck[n]) {
                ck[n] = true;
                w = s;
            }
            else {
                if (w == s) {
                    continue;
                }
                result--;
                break;
            }
        }
    }

    cout << result;
}