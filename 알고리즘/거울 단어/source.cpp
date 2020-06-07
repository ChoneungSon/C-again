#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	// your code goes here
	int n, flag;
	std::cin >> n;
	
	std::string word;

	std::map<char, char> arr;
	
	arr.insert(std::make_pair('b', 'd')); arr.insert(std::make_pair('d', 'b'));
	arr.insert(std::make_pair('i', 'i')); arr.insert(std::make_pair('l', 'l'));
	arr.insert(std::make_pair('o', 'o')); arr.insert(std::make_pair('p', 'q'));
	arr.insert(std::make_pair('q', 'p')); arr.insert(std::make_pair('v', 'v'));
	arr.insert(std::make_pair('w', 'w')); arr.insert(std::make_pair('m', 'm'));
	arr.insert(std::make_pair('n', 'n'));	arr.insert(std::make_pair('s', 'z'));
	arr.insert(std::make_pair('u', 'u'));	arr.insert(std::make_pair('z', 's'));
	arr.insert(std::make_pair('x', 'x'));

	for (int tc=0; tc<n; tc++) {
		flag = 1;
		std::cin >> word;
		for (int i=0; i<=word.length()/2; i++) {
			auto itr = arr.find(word[i]);
			if (itr == arr.end() || arr[word[i]] != word[word.length()-i-1]) {
				flag = 0;
				std::cout << "Normal" << std::endl;
				break;
			}
		}
		if (flag) std::cout << "Mirror" << std::endl;
	}
	
	return 0;
}