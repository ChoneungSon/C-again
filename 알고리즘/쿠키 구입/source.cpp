#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int n = cookie.size();
    int answer = 0;

    for (int i=0; i<n-1; i++) {
        int front = cookie[i]; int f_idx = i;
        int back = cookie[i+1]; int b_idx = i+1;

        while (1) {
            if (front == back) answer = max(answer, front);
            if (f_idx>0 && front <= back) {
                f_idx--;
                front += cookie[f_idx];
            } else if (b_idx<n-1 && front >= back) {
                b_idx++;
                back += cookie[b_idx];
            } else break;
        }
    }

    return answer;
}