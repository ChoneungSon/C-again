#include <iostream>
int main() {
    int n; int arr[2] = {1, 1};
    std::cin >> n;
    for (int i=2; i<n+1; i++) {
        arr[i%2] = (arr[(i+1)%2] + arr[i%2]) % 15746;
    }
    std::cout << arr[n%2] << std::endl;
    return 0;
}
