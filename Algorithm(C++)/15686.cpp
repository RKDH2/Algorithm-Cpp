#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;

vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<pair<int, int>> working_chicken;

int N, M;
int distance_min = INT_MAX;

void check(int nth, int open) {

    if (open == M) {
        int cur_res = 0;
        for (auto h : home) {
            int result = INT_MAX;
            for (auto c : working_chicken) {
                int ds = abs(h.first - c.first) + abs(h.second - c.second);
                result = min(result, ds);
            }
            cur_res += result;
        }
        distance_min = min(distance_min, cur_res);

        return;
    }
    if (nth >= chicken.size()) {
        return;
    }
    working_chicken.push_back(chicken[nth]);
    check(nth + 1, open + 1);
    working_chicken.erase(working_chicken.begin() + open);
    check(nth + 1, open);
}

int main() {
    cin >> N >> M;

    int** ck = new int* [N];
    for (int i = 0; i < N; ++i) {
        ck[i] = new int[N];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> ck[i][j];
            if (ck[i][j] == 1) {
                home.push_back({ i, j });
            }
            else if (ck[i][j] == 2) {
                chicken.push_back({ i, j });
            }
        }
    }

    check(0, 0);
    cout << distance_min;
}