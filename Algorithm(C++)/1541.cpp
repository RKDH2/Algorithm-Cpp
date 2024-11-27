#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string nums;
    cin >> nums; // ���� �Է� : "55-50+40"

    int total = 0; // ���� ����� ������ ����
    bool isSub = false; // ���� '-' ���� �������� Ȯ���ϴ� �÷���
    string num; // ���� ���ڸ� ������ ����

    for (int i = 0; i <= nums.size(); ++i) { // ������ ���ڸ� �����ؼ� �ݺ�
        if (nums[i] == '+' || nums[i] == '-' || nums.size() == i) {
            if (isSub) {
                total -= stoi(num); // '-' ����: ���� ���ڸ� ��
            }
            else {
                total += stoi(num); // '+' �Ǵ� �ʱ� ����: ���� ���ڸ� ����
            }
            num = ""; // ���� ���ڿ� �ʱ�ȭ

        }
        else {
            num += nums[i]; // ���� ���ڸ� ���� ���� ���ڿ��� �߰��ؼ� ����
        }

        // '-' �����ڸ� ������ isSub�� true�� ����
        if (nums[i] == '-') {
            isSub = true;
        }
    }

    cout << total;
}