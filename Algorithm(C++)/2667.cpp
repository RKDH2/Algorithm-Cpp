#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[26][26];
bool visited[26][26];
int cnt = 0;
int N;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<int> answer;


void dfs(int x, int y) {
    cnt++;
    visited[x][y] = true;
    int nx, ny;
    for (int i = 0; i < 4; ++i) {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx < N && ny < N && nx >= 0 && ny >= 0) {
            if (!visited[nx][ny] && board[nx][ny] == 1) {
                dfs(nx, ny);
            }
        }
    }

}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < N; ++j) {
            board[i][j] = line[j] - '0';
        }
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 1 && visited[i][j] == false) {
                cnt = 0;
                dfs(i, j);
                count++;
                answer.push_back(cnt);
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << count << '\n';
    for (auto num : answer) {
        cout << num << '\n';
    }
}