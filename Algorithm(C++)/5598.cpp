#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string word; cin >> word;
    for (char& s : word) {
        s -= 3;
        if (s < 'A') {
            s += 26;
        }
    }
    cout << word << '\n';
}