#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    while (N--) {
        string add;
        cin >> add;

        int a = add[0] - '0';
        int b = add[2] - '0';

        cout << a + b << '\n';
    }
}