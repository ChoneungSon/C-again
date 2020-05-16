# 클래스

* 생성자는 python의 `__init__`을 따로 지정하지 않고, 클래스의 이름을 쓰고, 옆에 멤버 변수를 지정하는 것으로 대신한다.
* 이때, `변수형 변수명 = 값` 으로 지정하면 원하는 변수에 대입한 값으로 디폴트 값이 지정된다.

* 인스턴스 변수를 호출하기 위해서는 객체의 `public` 연산자 아래 위치해야 한다. `public` 아래 위치하지 않는 변수들은 `private` 취급이 되어 호출이 불가능함.

* 소멸자: `~클래스명()` 으로 설정함.
* 배열의 동적할당 종료는 `delete[] (변수명)` 으로 한다.
* 복사 생성자
  * `(클래스명)(const (클래스명)& 복사객체명);`으로 정의한다.
  * 함수 내부에서 받은 인자의 값을 변화시키는 일이 없다면 `const`를 붙여야 한다.
  * 디폴트 복사 생성자를 사용하면 깊은 복사가 불가능하다.
  * string을 동적할당으로 설정하게 되면, 소멸자 내부에 동적할당된 변수를 delete 처리해야 한다. 이 과정에서 이미 생성된 객체를 복사 생성자를 이용해 복사를 하게 되면 이미 해제된 메모리를 다시 해제하게 되면서 오류가 발생한다.
  * 이러한 오류를 방지하기 위해 복사 생성자 내부에 string을 받기 위한 메모리를 동적할당해서 받는 방법이 있다. 이의 과정이 깊은 복사를 하는 방법이다.

* 클래스의 `static` 멤버 변수의 경우, 다른 멤버 변수들 처럼 객체가 소멸할 때 소멸되는 것이 아닌 프로그램이 종료될 때 소멸됨.
* `this` : 객체 자신을 가리키는 포인터, python 에서의 `self`와 동일한 느낌

```c++
// 레퍼런스를 리턴하는 함수
#include <iostream>

class A {
	int x;

public:
	A(int c) : x(c) {}
	int& access_x() { return x; } // x의 레퍼런스를 리턴한다.
	int get_x() { return x; } // x의 값을 리턴한다.
	void show_x() { std::cout << x << std::endl; }
};

int main() {
	A a(5);
	a.show_x(); // 5

	int& c = a.access_x(); // c는 a.x의 레퍼런스를 리턴한다.
	c = 4; // a.x를 바꾸는 것과 동일함.
	a.show_x(); // 4

	int d = a.access_x(); // int 변수에 레퍼런스 값을 전달 따라서 값이 복사되어서 d에 전달된다.
	d = 3; // d값만 3으로 변경됨.
	a.show_x(); // 4

	// 아래는 오류
	// int& e = a.get_x(); // 값이 레퍼런스 공간에 저장될 수 없음.
	// e = 2;
	// a.show_x();
    // 레퍼런스가 아닌 타입을 리턴하는 경우는 값의 복사가 이뤄진다.
    // 이후, 임시 객체가 생성된다.
    // 임시 객체의 레퍼런스를 가질 수 없다.
    // 문장이 끝나면 임시 객체가 삭제되기 때문에 레퍼런스 값을 받았어도, 이미 존재하지 않는 것에 대한 레퍼런스가 되기 때문에 오류가 난다.

	int f = a.get_x(); // f에 a.x의 값이 저장된다.
	f = 1; // f의 값만 변경됨.
	a.show_x(); // 4

	return 0;
}
```

```c++
Marine& Marine::be_attacked(int damage) {
    hp -= damage;
    if (hp <= 0) {is_dead = true;}
    return *this; // this가 포인터이기 때문에 *this는 객체 자신을 반환
} // Marine& 이기 때문에 객체의 레퍼런스를 받는다.

...
    
marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());
// [marine2.be_attacked(marine1.attack())] 부분이 실행되고, 이 객체 자신을 반환한다. 따라서 marine2가 되고, 다시 뒤의 함수가 실행되면서, 변환된 marine2를 반환한다.
```

* `explict`: 원하지 않는 암시적 변환을 막는다. `explict (클래스명)(매개변수)` 로 쓰인다.
* `mutable` : `const` 함수 안에서 해당 멤버 변수에 const 가 아닌 작업을 할 수 있게 만든다.



# 연산자 오버로딩

* `(리턴 타입) operator(연산자) (연산자가 받는 인자)`
* 형변환 `static_cast<int>(variable)`



# N 차원 배열 만들기

```c++
// 2차원 배열 만들기
int** arr;
arr = new int*[x1];
for (int i=0; i<x1; i++) arr[i] = new int[x2];
```

