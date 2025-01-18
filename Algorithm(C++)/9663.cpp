#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, result;
vector<int> board;

bool promising(int target) {
    if (board.empty()) {
        return true;
    }
    else {
        int nowPosition = board.size();
        for (int i = 0; i < nowPosition; ++i) {
            int current = board[i];
            bool horizonRule = (target == current);
            bool diagonalRule = (abs(nowPosition - i) == abs(target - current));
            if (horizonRule == true || diagonalRule == true) {
                return false;
            }
        }
        return true;
    }
}

void bk(int s) {
    for (int i = 0; i < n; ++i) {
        if (promising(i)) {
            board.push_back(i);
            if (board.size() == n) {
                result++;
                board.pop_back();
            }
            else {
                bk(s - 1);
            }
        }
    }
    board.pop_back();
}

int main() {
    cin >> n;

    bk(n);
    cout << result;
}