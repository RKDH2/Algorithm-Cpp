#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

const int INF = 1000000000; // 비교를 > 연산으로 했으므로 정확히 1e9 값이어야 함

int main() {
    bool flag = true;
    while (true) {
        vector<pair<string, long long>> cmd;
        string word;
        while (true) { // 프로그램을 구성하는 명령어 저장
            cin >> word;
            long long num = 0;
            if (word == "QUIT") return 0;
            if (word == "NUM") {
                cin >> num;
            }
            if (word == "END") break;
            cmd.push_back({ word, num });
        }
        int t;
        cin >> t;
        vector<long long> vc(t);

        for (int x = 0; x < t; x++) { // 입력값들 저장
            cin >> vc[x];
            stack<long long> st; // 입력값들 전부 long long으로
            st.push(vc[x]);
            bool isError = false; // 맨 마지막 스택 사이즈가 1일 때 에러 출력 겹치지 않게 하기 위함
            for (int i = 0; i < cmd.size(); i++) { // 각 입력값에 대해 프로그램 수행
                string c1 = cmd[i].first;
                if (c1 == "NUM") { int c2 = cmd[i].second; st.push(c2); }
                else if (c1 == "POP") {
                    if (!st.empty()) st.pop();
                    else { isError = true; break; }
                }
                else if (c1 == "INV") {
                    if (!st.empty()) {
                        long long tmp = st.top();
                        st.pop();
                        st.push(-tmp);
                    }
                    else { isError = true; break; }
                }
                else if (c1 == "DUP") {
                    // st.push(st.top()); // top 확인 시 empty 사용 필수
                    if (!st.empty()) { st.push(st.top()); }
                    else { isError = true; break; }
                }
                else if (c1 == "SWP") {
                    if (st.size() < 2) { isError = true; break; }
                    long long n1 = st.top(); st.pop();
                    long long n2 = st.top(); st.pop();
                    st.push(n1);
                    st.push(n2);
                }
                else if (c1 == "ADD") {
                    if (st.size() < 2) { isError = true; break; }
                    long long n1 = st.top(); st.pop();
                    long long n2 = st.top(); st.pop();
                    long long add = n1 + n2;
                    if (abs(add) > INF) { // 음수 덧셈의 경우도 포함
                        isError = true;
                        break;
                    }
                    st.push(add);
                }
                else if (c1 == "SUB") {
                    if (st.size() < 2) { isError = true; break; }
                    long long n1 = st.top(); st.pop();
                    long long n2 = st.top(); st.pop();
                    long long sub = n2 - n1;
                    if (abs(sub) > INF) { // n2가 음수, n1이 양수이면 절대값 초과 가능성 있음
                        isError = true;
                        break;
                    }
                    st.push(sub);
                }
                else if (c1 == "MUL") {
                    if (st.size() < 2) { isError = true; break; }
                    long long n1 = st.top(); st.pop();
                    long long n2 = st.top(); st.pop();
                    long long mul = n1 * n2;
                    if (abs(mul) > INF) { isError = true; break; }
                    st.push(mul);
                }
                else if (c1 == "DIV") {
                    if (st.size() < 2) { isError = true; break; }
                    long long n1 = st.top(); st.pop();
                    long long n2 = st.top(); st.pop();
                    if (n1 == 0) { isError = true; break; }
                    int cnt = 0;
                    if (n1 < 0) { cnt++; n1 *= -1; }
                    if (n2 < 0) {
                        cnt++;
                        n2 *= -1;
                    }
                    int div = 0;
                    if (cnt == 1) {
                        div = -(n2 / n1);
                    }
                    else {
                        div = n2 / n1;
                    }
                    st.push(div);
                }
                else if (c1 == "MOD") {
                    if (st.size() < 2) { isError = true; break; }
                    long long n1 = st.top(); st.pop();
                    long long n2 = st.top(); st.pop();
                    if (n1 == 0) { isError = true; break; }
                    if (n2 < 0) {
                        long long mod = abs(n2) % abs(n1);
                        st.push(-mod);
                    }
                    else {
                        long long mod = abs(n2) % abs(n1);
                        st.push(mod);
                    }
                }
            } // 프로그램 수행 반복 끝

            if (st.size() != 1 || isError) {
                cout << "ERROR\n";
            }
            else {
                cout << st.top() << '\n';
            }
        } // 입력값 루프 끝
        cout << "\n"; // 각 프로그램 사이에 줄바꿈 존재
    } // 전체 while => 프로그램 N개 반복 끝
    return 0;
}