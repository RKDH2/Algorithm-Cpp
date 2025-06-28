#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        map<string, int> fashion;
        int n, result = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string name, type;
            cin >> name >> type;
            if (fashion.find(type) == fashion.end()) {
                fashion.insert({ type, 1 });
            }
            else {
                fashion[type] += 1;
            }
        }
        int ans = 1;
        for (auto it = fashion.begin(); it != fashion.end(); it++) {
            ans *= it->second + 1;
        }
        ans--;
        cout << ans << '\n';
    }
}