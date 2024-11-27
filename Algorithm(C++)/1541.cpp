#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string nums;
    cin >> nums; // 수식 입력 : "55-50+40"

    int total = 0; // 최종 결과를 저장할 변수
    bool isSub = false; // 현재 '-' 연산 이후인지 확인하는 플래그
    string num; // 현재 숫자를 저장할 변수

    for (int i = 0; i <= nums.size(); ++i) { // 마지막 문자를 포함해서 반복
        if (nums[i] == '+' || nums[i] == '-' || nums.size() == i) {
            if (isSub) {
                total -= stoi(num); // '-' 이후: 현재 숫자를 뺌
            }
            else {
                total += stoi(num); // '+' 또는 초기 상태: 현재 숫자를 더함
            }
            num = ""; // 숫자 문자열 초기화

        }
        else {
            num += nums[i]; // 숫자 문자를 현재 숫자 문자열에 추가해서 연결
        }

        // '-' 연산자를 만나면 isSub를 true로 설정
        if (nums[i] == '-') {
            isSub = true;
        }
    }

    cout << total;
}