#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int library(vector<int>& st, vector<int>& ed) {
    int ans = 0;
    for (int i = 0; i < st.size(); i += m) {
        ans += st[i] * 2;
    }
    for (int i = 0; i < ed.size(); i += m) {
        if (i == 0) {
            ans += ed[i];
        }
        else {
            ans += ed[i] * 2;
        }
    }

    return ans;
}

int main() {
    cin >> n >> m;
    vector<int> pv;
    vector<int> nv;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num > 0) {
            pv.push_back(num);
        }
        else {
            nv.push_back(-num);
        }
    }
    sort(pv.rbegin(), pv.rend());
    sort(nv.rbegin(), nv.rend());

    // 만약 pv가 비어있을 경우
    if (pv.size() == 0) {
        // 한 번만 계산되는 부분에 nv를 넣기
        int res = library(pv, nv);
        cout << res;
    }
    // 만약 nv가 비어있을 경우
    else if (nv.size() == 0) {
        // 한 번만 계산되는 부분에 pv를 넣기
        int res = library(nv, pv);
        cout << res;
    }
    // 거리가 먼 요소를 한 번만 계산되는 부분에 넣기
    else if (pv.front() < nv.front()) {
        int res = library(pv, nv);
        cout << res;
    }
    else {
        int res = library(nv, pv);
        cout << res;
    }
}