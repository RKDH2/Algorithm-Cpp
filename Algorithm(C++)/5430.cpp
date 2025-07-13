#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string p; // �Լ� �ޱ�
        cin >> p;
        int n;
        cin >> n;
		string nums; // �迭 �ޱ�
        cin >> nums;
        string tmp = "";
        deque<int> dq;
        for (int i = 1; i < nums.length(); i++) {
            if (nums[i] == ',' || nums[i] == ']') {
                if (tmp != "") {
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
            }
            else {
                tmp += nums[i];
            }
        }
        bool swap = false; // ������
        bool error = false;
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') {
                swap = !swap; // ������
            }
            else if (p[i] == 'D') {
                if (dq.empty()) {
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
                if (!swap) {
                    dq.pop_front();
                }
                else {
                    dq.pop_back();
                }
            }
        }
        if (error) continue;
        cout << '[';
        while (dq.size() > 1) {
            if (!swap) {
                cout << dq.front() << ',';
                dq.pop_front();
            }
            else {
                cout << dq.back() << ',';
                dq.pop_back();
            }
        }
        if (!dq.empty()) cout << dq.front() << ']' << '\n';
        else cout << ']' << '\n';
    }
}