#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string nums;
    cin >> nums;

    int total = 0;
    bool isSub = false;
    string num;

    for (int i = 0; i <= nums.size(); ++i) {
        if (nums[i] == '+' || nums[i] == '-' || nums.size() == i) {
            if (isSub) {
                total -= stoi(num);
            }
            else {
                total += stoi(num);
            }
            num = "";

        }
        else {
            num += nums[i];
        }

        if (nums[i] == '-') {
            isSub = true;
        }
    }

    cout << total;
}