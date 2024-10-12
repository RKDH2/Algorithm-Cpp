#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string word; cin >> word;
    for (char& c : word) {
        if (islower(c)) {
            c = toupper(c);
        }
        else if (isupper(c)) {
            c = tolower(c);
        }
    }

    cout << word << '\n';
}