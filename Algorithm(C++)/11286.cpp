#include <iostream>
#include <cstdlib>
using namespace std;

class absHeap {

    int* heap = nullptr;
    int cap = 0;
    int size = 0;

    int parent(int x) {
        return (x - 1) / 2;
    }

    int left(int x) {
        if (x * 2 + 1 >= size) {
            return -1;
        }
        return (x * 2) + 1;
    }

    int right(int x) {
        if (x * 2 + 2 >= size) {
            return -1;
        }
        return (x * 2) + 2;
    }

    bool isFrontSmaller(int x, int y) {
        int front = heap[x];
        int back = heap[y];

        if (abs(front) == abs(back))
            return front < back;

        return abs(front) < abs(back);
    }

    void resize() {
        //원래 비어있었다면?
        if (cap == 0) {
            heap = new int[1];
            cap = 1;
        }//크기가 커지면?
        else if (size > cap) {
            int* new_heap = new int[cap * 2];
            for (int i = 0; i < size; i++) {
                new_heap[i] = heap[i];
            }
            delete[] heap;
            heap = new_heap;
            cap *= 2;
        }//크기가 작아지면?
        else if (size < cap / 4) {
            int* new_heap = new int[cap / 2];
            for (int i = 0; i < size; i++) {
                new_heap[i] = heap[i];
            }
            delete[] heap;
            heap = new_heap;
            cap /= 2;
        }
    }

    void heapify_up() {
        int idx = size - 1;
        while (idx != 0 && isFrontSmaller(idx, parent(idx))) {
            //swap
            int temp = heap[idx];
            heap[idx] = heap[parent(idx)];
            heap[parent(idx)] = temp;
            idx = parent(idx);
        }
    }

    void heapify_down(int idx) {
        int root = idx;
        int x = left(idx);
        int y = right(idx);
        if (x != -1 && isFrontSmaller(x, root)) {
            root = x;
        }
        if (y != -1 && isFrontSmaller(y, root)) {
            root = y;
        }
        if (root != idx) {
            int temp = heap[idx];
            heap[idx] = heap[root];
            heap[root] = temp;
            heapify_down(root);
        }
    }

public:
    void push(int x) {
        size++;
        resize();
        heap[size - 1] = x;
        heapify_up();
    }

    int pop() {
        if (size == 0) {
            return 0;
        }
        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        resize();
        heapify_down(0);
        return root;
    }
};

int main() {
    absHeap heap;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x == 0) {
            cout << heap.pop() << '\n';
        }
        else {
            heap.push(x);
        }
    }
}