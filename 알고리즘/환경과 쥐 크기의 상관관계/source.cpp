#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, num;
    int maxA=0; int maxB=0; int numA=0; int numB=0;
    int sumA=0; int sumB=0;

    std::cin >> n;

    std::vector <int> vA(100001);
    std::vector <int> vB(100001);

    for (int i=1; i<=n; i++) {
        std::cin >> num;
        vA[num]++;
    }

    for (int i=1; i<=n; i++) {
        std::cin >> num;
        vB[num]++;
    }

    for (int i=1; i<=100001; i++) {
        if (i>5) {
            sumA -= vA[i-5];
            sumB -= vB[i-5];
        }
        sumA += vA[i];
        sumB += vB[i];
        if (maxA < sumA) {maxA = sumA; numA = i;}
        if (maxB < sumB) {maxB = sumB; numB = i;}
    }

    std::cout << numA-2 << " " << numB-2 << std::endl;

    if (numA > numB) std::cout << "good" << std::endl;
    else std::cout << "bad" << std::endl;

    return 0;
}