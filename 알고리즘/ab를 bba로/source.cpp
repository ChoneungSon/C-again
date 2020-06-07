#include <iostream>
#include <string>
#include <cmath>
#include <vector>

int main() {
    std::vector <int> arr(1000000);
    std::vector <int> between(1000000);

    std::string str;

    int front = 0; int back = 0;
    int cnt; int flag = 1;

    std::cin >> str;

    for (int i=0; i<str.length(); i++) {
        if (flag) {
            if (str[i]=='b') {
                arr[front] = cnt;
                cnt = 1;
                front++;
                flag = 0;
            }
            else cnt++;
        }
        else {
            if (str[i]=='a') {
                between[back] = cnt;
                cnt = 1;
                back++;
                flag = 1;
            }
            else cnt++;
        }
    }
    if (flag) {arr[front] = cnt; front++;}
    else {between[back] = cnt; back++;}

    long long result = 0; long long init = between[back-1];
    long long div = pow(10, 9) + 7;
	
    for (int i=back-1; i>0; i--) {
        result = (result + init * static_cast<long long>((pow(2, arr[i])-1))) % div;
        init = (between[i-1] + init * static_cast<long long>(pow(2, arr[i]))) % div;
    }
    result = (result + init * static_cast<long long>((pow(2, arr[0])-1))) % div;
	
    std::cout << result % div << std::endl;

    return 0;
}