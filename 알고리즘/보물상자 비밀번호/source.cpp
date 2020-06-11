#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map <char, int> nums = {
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
        {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15},
    };

int main() {
    int tc;
    string str;
    vector<long> num(28);
    cin >> tc;
    for (int cs=1; cs<=tc; cs++) {
        int start=-1;
        int n, k;
        cin >> n >> k >> str;
        for (int i=0; i<n; i++) {
            int number = 0; int flag = 1;
            for (int j=0; j<n/4; j++) {
                number = 16*number + nums[str[(i+j)%n]];
            }
            for (int j=0; j<=start; j++) {
                if (num[j] == number) {
                    flag = 0; break;
                }
            } 
            if (flag) { start++; num[start] = number; }
        }
        sort(num.begin(), num.begin()+start+1, greater<long>());
        for (int i=0; i<=start; i++) cout << num[i] << " ";
        cout << endl;
        cout << "#" << cs << " " << num[k-1] << endl;
    }

    return 0;
}