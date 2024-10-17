#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string ck[7] = {
        "Never gonna give you up",
        "Never gonna let you down",
        "Never gonna run around and desert you",
        "Never gonna make you cry",
        "Never gonna say goodbye",
        "Never gonna tell a lie and hurt you",
        "Never gonna stop" };
    int n;
    string word;
    bool result_word = true;
    cin >> n; cin.ignore();
    while (n--) {
        getline(cin, word);
        bool is_word = false;
        for (int i = 0; i < 7; ++i) {
            if (word == ck[i]) {
                is_word = true;
                break;
            }
        }

        if (!is_word) result_word = false;
    }

    if (result_word) {
        cout << "No" << '\n';
    }
    else {
        cout << "Yes" << '\n';
    }
}