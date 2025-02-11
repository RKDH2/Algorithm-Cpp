#include <iostream>
#include <algorithm>

using namespace std;

int arr[500001];
int sorted[500001];

long long swapCount = 0;

void Merge(int start, int end) {

    int mid = (start + end) / 2;

    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            sorted[k++] = arr[i++];
        }
        else {
            sorted[k++] = arr[j++];
            swapCount += (mid - i + 1);
        }
    }

    while (i <= mid) sorted[k++] = arr[i++];
    while (j <= end) sorted[k++] = arr[j++];

    for (int p = start; p <= end; p++) {
        arr[p] = sorted[p];
    }
}

void MergeSort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(start, mid);
        MergeSort(mid + 1, end);
        Merge(start, end);
    }
}


int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    MergeSort(0, N - 1);

    cout << swapCount;
}