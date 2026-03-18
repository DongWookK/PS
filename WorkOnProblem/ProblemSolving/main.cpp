#include "pre.h"
using arr_t = std::array<int32_t, 100000>;

int main() {
    arr_t arr{};
    int32_t n;
    cin >> n;

    for (int32_t i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // todo
    // ...

    for (int32_t i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}