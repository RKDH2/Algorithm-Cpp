#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> meetings(n);
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        meetings[i] = { end, start };
    }

    sort(meetings.begin(), meetings.end());

    int cnt = 0;
    int meeting_end_time = 0;

    for (pair<int, int>& meeting : meetings) {
        int start = meeting.second;
        int end = meeting.first;

        if (start >= meeting_end_time) {
            cnt++;
            meeting_end_time = end;
        }
    }

    cout << cnt << '\n';
}