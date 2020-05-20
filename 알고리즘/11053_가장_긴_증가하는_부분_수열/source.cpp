#include <iostream>
#include <vector>

int main() {
    int n, max_idx, max_cnt = 1;
    std::cin >> n;
    std::vector<int> arr(n);
    std::vector<int> vec(n); vec[0] = 1;
    for (int i=0; i<n; i++) std::cin >> arr[i];
    for (int i=1; i<n; i++) {
        max_idx = i;
        for (int j=0; j<i; j++) {
            if (arr[j] < arr[i] && vec[j] > vec[max_idx]) max_idx = j;
        }
        vec[i] = vec[max_idx] + 1;
        if (max_cnt < vec[i]) max_cnt = vec[i];
    }
    std::cout << max_cnt << std::endl;
    return 0;
}