#include <iostream>
#include <math.h>

int main() {
    int n, cnt = 0;
    long long memo[31] = {0,};

    std::cin >> n;
    
    for (int i=1; i<=n; i++) {
        if (i < 2) memo[i] = 3;
        else memo[i] = memo[i-1] + 3*(memo[i-1]-memo[i-2]);
    }

    for (int i=0; i<=n; i++) std::cout << memo[i] << std::endl;

    return 0;
}