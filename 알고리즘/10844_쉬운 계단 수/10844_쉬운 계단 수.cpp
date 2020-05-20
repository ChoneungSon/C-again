#include <iostream>
#include <vector>

int main() {
    int n, sum=0;
    std::cin >> n;
    if (n == 1) {std::cout << 9 << std::endl; return 0;}
    else {
        std::vector<int> vec(10, 1);
        vec[0] = 0;
        for (int cnt=0; cnt < n-1; cnt++) {
            std::vector<int> arr(10);
            for (int i=0; i<10; i++) {
                if (i-1 >= 0) {arr[i-1] = (arr[i-1] + vec[i]) % 1000000000;}
                if (i+1 < 10) {arr[i+1] = (arr[i+1] + vec[i]) % 1000000000;}
            }
            vec.clear();
            vec.assign(arr.begin(), arr.end());
        }
        for (int i=0; i<10; i++) sum = (sum+vec[i]) % 1000000000;
        std::cout << sum << std::endl;
        return 0;
    }
}