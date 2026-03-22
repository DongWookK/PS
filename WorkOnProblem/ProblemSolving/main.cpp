#include "pre.h"
using arr_t = std::vector<int32_t>;

// 상향식 힙정렬
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

void bottom_top_heapify(arr_t arr, int32_t n)
{
    for (int32_t i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    arr_t arr{};
    int32_t input{};

    int32_t n;
    cin >> n;

    for (int32_t i = 0; i < n; ++i) {
        cin >> input;

        if (int32_t{} != input)
        {
            arr.push_back(input);
            bottom_top_heapify(arr, arr.size());
        }
        else
        {
            cout << arr[0] << endl;
            arr.erase(arr.begin());
        }
    }

    for (int32_t i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}