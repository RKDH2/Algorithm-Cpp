#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vc(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }
    int st = 0, ed = k - 1, maxi, tmp = 0;
    for (int i = st; i < k; i++) tmp += vc[i];
    maxi = tmp;
    while (ed < n - 1) {
        tmp -= vc[st];
        st++;
        tmp += vc[ed + 1];
        ed++;
        maxi = max(maxi, tmp);
    }
    cout << maxi;
}