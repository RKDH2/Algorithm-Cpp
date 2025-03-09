#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < N - 1; ++i) {
        int load;
        cin >> load;
        v1.push_back(load);
    }
    for (int i = 1; i <= N; ++i) {
        int node;
        cin >> node;
        v2.push_back(node);
    }
    int price = v2[0];
    long long result = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (v2[i] < price) {
            price = v2[i];
        }

        result += price * v1[i];
    }

    cout << result;
}