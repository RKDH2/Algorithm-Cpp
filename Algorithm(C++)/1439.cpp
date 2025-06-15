#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string word;
    cin >> word;
    int zero = 0, one = 0, result = 0;
    for (int i = 0; i < word.size(); i++) {
        if (i == word.size() - 1 && word[i] != word[i - 1]) {
            if (word[i] == '1') {
                one++;
            }
            else {
                zero++;
            }
        }
        if (i == word.size()) break;

        if (word[i] != word[i + 1] && word[i] == '1') {
            one++;
        }
        else if (word[i] != word[i + 1] && word[i] == '0') {
            zero++;
        }
    }
    int point = min(zero, one);
    cout << point;
}