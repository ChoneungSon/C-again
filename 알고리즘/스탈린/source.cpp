#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, left, right, mid;
    int arr[1000000];
    int maxlen[1000000];

    std::cin >> n;
    for (int i=0; i<n; i++) std::cin >> arr[i];
    maxlen[0] = 1000000001;
    int front = 0;

	for (int i=0; i<n; i++) {
		if (maxlen[front] < arr[i]) {
			front++;
			maxlen[front] = arr[i];
		} else {
			left = 0; right = front;
			while (left != right) {
				mid = (right+left)/2;
				if (maxlen[mid] < arr[i]) left=mid+1;
				else right=mid;
			}
			maxlen[right] = arr[i];
		}
	}
	
	std::cout << n-front-1 << std::endl;
    return 0;
}