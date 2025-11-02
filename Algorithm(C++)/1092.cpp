#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; i++) { // N개의 크레인 무게 제한
        cin >> vc[i];
    }
    cin >> m;
    vector<int> box(m);
    for (int i = 0; i < m; i++) { // M개의 박스 무게
        cin >> box[i];
    }

    // 오름차순 정렬
    sort(vc.rbegin(), vc.rend()); // vc(크레인 중량)
    sort(box.rbegin(), box.rend()); // box(박스 무게)

    if (vc[0] < box[0]) { // 가장 튼튼한 크레인이 가장 무거운 박스 못옮김
        cout << -1;
        return 0;
    }

    int res = 0; // 시간 (분)
    int moved = 0; // 옮긴 박스 수
    vector<bool> checked(m, false); // 해당 idx 박스를 옮긴 여부
    while (moved < m) {
        int boxidx = 0;
        for (int i = 0; i < n; i++) { // 크레인 순회
            while (boxidx < m) { // 범위 체크
                if (!checked[boxidx] && vc[i] >= box[boxidx]) { // 방문 X, 옮길 수 있을 경우 (1)
                    checked[boxidx] = true; // 방문 O
                    moved++; // 박스 옮김
                    boxidx++; // 다음 박스로 이동
                    break;
                }
                boxidx++; // 조건 (1)을 불총족시 다음 박스로 이동
            }
        }
        res++; // 1분 추가
    }
    cout << res;
    return 0;
}