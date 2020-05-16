// 1. 문자(char)로 부터의 문자열 생성, 문자열(char *)로 부터의 생성
// 2. 문자열 길이를 구하는 함수
// 3. 문자열 뒤에 다른 문자열 붙이기
// 4. 문자열 내에 포함되어 있는 문자열 구하기
// 5. 문자열이 같은지 비교
// 6. 문자열 크기 비교

#include <string.h>
#include <iostream>

class MyString {
public:
	char* string;
	int length;
	MyString(char word);
	MyString(const char* word);
	~MyString();
	void print();
	void add(const char* word);
	bool same(const char* word);
	bool compare(const char* word);
};
MyString::MyString(char word) {
	length = 1;
	string = new char[2];
	string[0] = word; string[1] = '\0';
}
MyString::MyString(const char* word) { 
	length = strlen(word);
	string = new char[length+1];
	for (int i = 0; i != length; i++) string[i] = word[i];
	string[length] = '\0';
}
MyString::~MyString() { delete[] string; }
void MyString::print() {
	std::cout << string << std::endl;
}
bool MyString::same(const char* word) {
	if (length != strlen(word)) return false;
	for (int i = 0; i != length; i++) {
		if (string[i] != word[i]) return false;
	}
	return true;
}
bool MyString::compare(const char* word) {
	int i = 0;
	while (string[i]) {
		if (!(word[i])) return false;
		else if (string[i] > word[i]) return false;
		else if (string[i] < word[i]) return true;
		i++;
	}
	if (word[i]) return false;
	else return true;
}
void MyString::add(const char* words) {
	char* temp = new char[length+1];
	for (int i = 0; i < length; i++) temp[i] = string[i];
	temp[length] = '\0';
	string = new char[length + strlen(words) + 1];
	for (int i = 0; i < length; i++) string[i] = temp[i];
	for (int i = 0; i < (int)strlen(words); i++) string[length + i] = words[i];
	string[length + strlen(words)] = '\0';
	length += strlen(words);
	delete[] temp;
}

int main() {
	MyString str("abcdedf");
	std::cout << str.same("ab") << std::endl;
	std::cout << str.compare("abcedf") << std::endl;
	str.add("abcedf");
	str.print();
	return 0;
}