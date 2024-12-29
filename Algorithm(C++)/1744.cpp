#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, num;
    cin >> N;

    vector<int> vc_p;
    vector<int> vc_m;

    for (int i = 0; i < N; ++i) {
        cin >> num;
        if (num > 0) {
            vc_p.push_back(num);
        }
        else {
            vc_m.push_back(num);
        }
    }

    sort(vc_p.rbegin(), vc_p.rend());
    sort(vc_m.begin(), vc_m.end());

    long long result = 0;

    for (int i = 0; i < vc_p.size(); ++i) {
        if (vc_p[i] == 1) {
            result += vc_p[i];
        }
        else {
            if (i + 1 < vc_p.size()) {
                if (vc_p[i + 1] == 1) {
                    result += vc_p[i] + vc_p[i + 1];
                }
                else {
                    result += vc_p[i] * vc_p[i + 1];
                }
                i++;
            }
            else {
                result += vc_p[i];
            }
        }
    }

    for (int i = 0; i < vc_m.size(); ++i) {
        if (i + 1 < vc_m.size()) {
            result += vc_m[i] * vc_m[i + 1];
            i++;
        }
        else {
            result += vc_m[i];
        }
    }

    cout << result;
}