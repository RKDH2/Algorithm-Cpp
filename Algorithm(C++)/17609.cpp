#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> vc(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }
    for (int i = 0; i < n; i++) {
        int st = 0, ed = vc[i].length() - 1;
        int check = false;
        while (st <= ed) {
            if (vc[i][st] != vc[i][ed]) {
                check = true;
                break;
            }
            st++; ed--;
        }
        if (check == false) {
            cout << 0 << '\n';
            continue;
        }

        st = 0; ed = vc[i].length() - 1;
        check = false;
        bool isO = false;
        while (st <= ed) {
            if (vc[i][st] != vc[i][ed]) {
                if (isO == false) {
                    st++;
                    isO = true;
                    continue;
                }
                else {
                    check = true;
                    break;
                }
            }
            st++; ed--;
        }
        if (check == false && isO == true) {
            cout << 1 << '\n';
            continue;
        }

        st = 0; ed = vc[i].length() - 1;
        check = false;
        isO = false;
        while (st <= ed) {
            if (vc[i][st] != vc[i][ed]) {
                if (isO == false) {
                    ed--;
                    isO = true;
                    continue;
                }
                else {
                    check = true;
                    break;
                }
            }
            st++; ed--;
        }
        if (check == false && isO == true) {
            cout << 1 << '\n';
            continue;
        }

        cout << 2 << '\n';
    }
}