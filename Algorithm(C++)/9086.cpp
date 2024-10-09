#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        char first_s = s[0];
        char last_s = s[s.size() - 1];
        cout << first_s << last_s << "\n";
    }
}