//#include <iostream>
//#include <vector>
//#include <set>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<string> VC;
//    set<string> ST;
//
//    for (int i = 0; i < n; ++i) {
//        string name;
//        cin >> name;
//        VC.push_back(name);
//        ST.insert(name);
//    }
//
//    int num[ST.size()];
//
//    for (string s : ST) {
//        cout << s << ' ' << count(VC.begin(), VC.end(), s) << '\n';
//    }
//}

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> VC;
    set<string> ST;
    set<pair <int, string>> RS;

    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        VC.push_back(name);
        ST.insert(name);
    }

    int num[ST.size()];

    for (const auto& s : ST) {
        RS.insert({ count(VC.begin(), VC.end(), s), s });
    }
    for (const auto& s : RS) {
        cout << s.second << ' ' << s.first << '\n';
    }
}