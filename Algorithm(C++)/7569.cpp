#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    int m, n, h;
    cin >> m >> n >> h;

    int*** boxes = new int** [h];

    for (int i = 0; i < h; i++) {
        boxes[i] = new int* [n];
        for (int j = 0; j < n; j++) {
            boxes[i][j] = new int[m];
        }
    }

    queue<tuple<int, int, int>> bfs_queue;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                int state;
                cin >> state;
                boxes[i][j][k] = state;
                if (state == 1) {
                    bfs_queue.push(make_tuple(i, j, k));
                }
            }
        }
    }

    int result = 0;
    const int dx[6] = { 0, 1, 0, -1, 0, 0 };
    const int dy[6] = { 1, 0, -1, 0, 0, 0 };
    const int dz[6] = { 0, 0, 0, 0, 1, -1 };

    while (!bfs_queue.empty()) {
        auto cur = bfs_queue.front();

        int x = get<2>(cur);
        int y = get<1>(cur);
        int z = get<0>(cur);

        bfs_queue.pop();

        for (int i = 0; i < 6; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            int new_z = z + dz[i];
            bool inside =
                new_x >= 0 && new_x < m &&
                new_y >= 0 && new_y < n &&
                new_z >= 0 && new_z < h;
            if (inside && boxes[new_z][new_y][new_x] == 0) {
                bfs_queue.push(make_tuple(new_z, new_y, new_x));
                boxes[new_z][new_y][new_x] = boxes[z][y][x] + 1;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (boxes[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                result = max(result, boxes[i][j][k]);
            }
        }
    }
    cout << result - 1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            delete[] boxes[i][j];
        }
        delete[] boxes[i];
    }
    delete[] boxes;
}
// ----------------------------- 새로운 풀이
//#include <algorithm>
//#include <iostream>
//#include <queue>
//#include <tuple>
//
//using namespace std;
//
//struct Pos {
//    int z, y, x;
//};
//
//int main() {
//    int m, n, h;
//    cin >> m >> n >> h;
//
//    int*** boxes = new int** [h];
//    for (int i = 0; i < h; i++) {
//        boxes[i] = new int* [n];
//        for (int j = 0; j < n; j++) {
//            boxes[i][j] = new int[m];
//        }
//    }
//
//    queue<Pos> BFQ;
//
//    for (int z = 0; z < h; z++) {
//        for (int y = 0; y < n; y++) {
//            for (int x = 0; x < m; x++) {
//                int state;
//                cin >> state;
//                boxes[z][y][x] = state;
//                if (state == 1) {
//                    BFQ.push({ z, y, x });
//                }
//            }
//        }
//    }
//
//    int result = 0;
//    const int dx[6] = { 0, 1, 0, -1, 0, 0 };
//    const int dy[6] = { 1, 0, -1, 0, 0, 0 };
//    const int dz[6] = { 0, 0, 0, 0, 1, -1 };
//
//    while (!BFQ.empty()) {
//        auto cur = BFQ.front(); BFQ.pop();
//        int z = cur.z;
//        int y = cur.y;
//        int x = cur.x;
//
//        for (int i = 0; i < 6; i++) {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//            int nz = z + dz[i];
//
//            if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)
//                continue;
//            if (boxes[nz][ny][nx] != 0)
//                continue;
//
//            BFQ.push({ nz, ny, nx });
//            boxes[nz][ny][nx] = boxes[z][y][x] + 1;
//        }
//    }
//    for (int z = 0; z < h; z++) {
//        for (int y = 0; y < n; y++) {
//            for (int x = 0; x < m; x++) {
//                if (boxes[z][y][x] == 0) {
//                    cout << -1;
//                    return 0;
//                }
//                result = max(result, boxes[z][y][x]);
//            }
//        }
//    }
//
//    cout << result - 1;
//
//    for (int i = 0; i < h; i++) {
//        for (int j = 0; j < n; j++) {
//            delete[] boxes[i][j];
//        }
//        delete[] boxes[i];
//    }
//    delete[] boxes;
//}