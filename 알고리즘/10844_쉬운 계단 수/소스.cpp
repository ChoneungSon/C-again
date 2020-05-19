#include <iostream>
#include <vector>

int main(void) {
	int n, sum = 0;
	std::cin >> n;
	if (n == 1) std::cout << 9 << std::endl; return 0;
	std::vector<int> v(10, 1);
	v[0] = 0;
	for (int i = 0; i <= n - 1; i++) {
		std::vector<int> arr(10);
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0) {
				arr[j - 1] = (arr[j - 1] + v[j]) % 1000000000;
				if (i == n - 1) sum = (sum + arr[j - 1]) % 1000000000;
			}
			if (j + 1 < 10) {
				arr[j + 1] = (arr[j + 1] + v[j]) % 1000000000;
				if (i == n - 1) sum = (sum + arr[j + 1]) % 1000000000;
			}
		}
		std::copy(arr.begin(), arr.end(), v.begin());
		std::cout << arr[0] << std::endl;
	}
	std::cout << sum << std::endl;

	return 0;
}