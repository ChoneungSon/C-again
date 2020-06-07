#include <iostream>
#include <algorithm>
#include <vector>

int length(int x, int y, int limit) {
    if (x < y) return limit+x-y;
    else return x-y;
}

int main() {
    int n, limit;
    std::cin >> n;
    std::cin >> limit;

    int arr[300001] = {0,};

    for (int i=1; i<=n; i++) {
        std::cin >> arr[i];
    }
	
    // 이분탐색으로 하는 방법
    int left, right, mid, temp;
    int max_value = 0;
    int min_value;
    for (int i=1; i<=n; i++) {
        left = arr[i-1]+1; right = i+limit-n;
        min_value = length(right, arr[i], limit);
        while (left != right) {
            mid = (left+right)/2;
            temp = length(mid, arr[i], limit);
            if (min_value > temp) {right = mid; min_value = temp;}
            else left = mid+1;
        }
        max_value = std::max(min_value, max_value);
        arr[i] = left;
    }
    
	std::cout << max_value << std::endl;

    return 0;
}