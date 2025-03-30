#include <iostream>

using namespace std;

int t_left[27];
int t_right[27];

void pre_order(int node) {
    cout << char(node + 'A');
    if (t_left[node] != -1) {
        pre_order(t_left[node]);
    }
    if (t_right[node] != -1) {
        pre_order(t_right[node]);
    }
}

void in_order(int node) {
    if (t_left[node] != -1) {
        in_order(t_left[node]);
    }
    cout << char(node + 'A');
    if (t_right[node] != -1) {
        in_order(t_right[node]);
    }
}

void post_order(int node) {
    if (t_left[node] != -1) {
        post_order(t_left[node]);
    }
    if (t_right[node] != -1) {
        post_order(t_right[node]);
    }
    cout << char(node + 'A');
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        char root, l, r;
        cin >> root >> l >> r;
        if (l == '.') {
            t_left[root - 'A'] = -1;
        }
        else {
            t_left[root - 'A'] = l - 'A';
        }
        if (r == '.') {
            t_right[root - 'A'] = -1;
        }
        else {
            t_right[root - 'A'] = r - 'A';
        }
    }

    pre_order(0);
    cout << "\n";
    in_order(0);
    cout << "\n";
    post_order(0);
}