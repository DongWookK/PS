#include "pre.h"
using arr_t = std::array<int32_t, 1000>;

// 힙 구조를 유지하는 함수
void heapify(arr_t& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int main() {
    arr_t arr{};
    int32_t n;
    cin >> n;

    for (int32_t i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 무작위 배열을 최대 힙으로 변환 (최초 생성은 자식까지 할필요없이 마지막 부모 노드 (n/2 - 1)만 하면 된다.)
    for (int32_t i = (n / 2) - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int32_t i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    // 결과 출력
    for (int32_t i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}