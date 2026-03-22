#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 삽입 시: 새로 추가된 노드를 위로 올림 (Heapify Up)
void push_heap(vector<int>& heap, int val) {
    heap.push_back(val);
    int idx = heap.size() - 1;
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] < heap[idx]) {
            swap(heap[parent], heap[idx]);
            idx = parent;
        }
        else {
            break;
        }
    }
}

// 삭제 시: 루트를 제거하고 마지막 원소를 아래로 내림 (Heapify Down)
void pop_heap(vector<int>& heap) {
    if (heap.empty()) {
        cout << 0 << "\n";
        return;
    }
    cout << heap[0] << "\n";

    // 1. 루트와 마지막 원소 교체 후 제거
    heap[0] = heap.back();
    heap.pop_back();

    // 2. 내려가며 정렬
    int i = 0;
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        }
        else {
            break;
        }
    }
}

int main() {
    // 입출력 속도 향상 (필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> heap;

    while (n--) {
        int x;
        cin >> x;
        if (x > 0) {
            push_heap(heap, x);
        }
        else {
            pop_heap(heap);
        }
    }
    return 0;
}