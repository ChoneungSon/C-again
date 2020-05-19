# string 클래스

```c++
#include <iostream>
#include <string>

int main() {
    // 표준이므로 std 안에 string 이 정의되어 있음.
    std::string s = "abc";
    
    std::cout << s << std::endl; // abc 가 출력
    
    return 0;
}
```

```c++
#include <iostream>
#include <string>

int main() {
    std::string s = "abc";
    std::string t = "def";
    std::string s2 = s;
    
    std::cout << s << "의 길이 : " << s.length() << std::endl;
    std::cout << s << "뒤에 " << t << "를 붙이면 : " << s+t << std::endl;
    if (s == s2) std::cout << s << "와 " << s2 << "는 같다." << std::endl;
    if (s != t) std::cout << s << "와 " << t << "는 다르다." << std::endl;
    
    return 0;
}
```



# 상속

* `class 클래스명 : public 상속받을 클래스명`

```c++
#include <iostream>
#include <string>

class Base {
    std::string s;
    
    public:
    Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }
    
    void what() { std::cout << s << std::endl; }
}
class Derived : public Base { // Base를 public 형식으로 상속 받는다
    std::string s;
    public:
    Derived() : Base(), s("파생") { // 상속 받을 클래스의 생성자를 호출해야 함
        std::cout << "파생 클래스" << std::endl;
        what();
    }
}
int main() {
    std::cout << "기반 클래스 생성" << std::endl;
    Base p;
    
    std::cout << "파생 클래스 생성" << std::endl;
    Derived c;
    
    return 0;
}
```

```bash
기반 클래스 생성
기반 클래스
파생 클래스 생성
기반 클래스 // 파생 클래스의 생성자가 호출되기 전에 기반 클래스의 생성자가 호출되기 때문
파생 클래스
기반 // what 함수는 Base 에만 정의되어 있기 때문에 Base의 s가 출력된다.
```

* 다른 클래스에 정의되어 있는 함수는 상속 받아도 다른 함수로 취급된다.
* `private` : 오직 본인 클래스에서만 접근가능한 변수나 함수 정의

* `protected` : 외부에서 접근은 못하지만 상속 클래스에서만 사용가능한 변수 정의
* `public` : 외부에서 접근 가능한 변수 정의

```c++
#include <iostream>
#include <string>

class Base {
    protected:
    std::string parent_string;
    public:
    Base() : parent_string("base") { std::cout << "base class" << std::endl; }
    void what() { std::cout << parent_string << std::endl; }
};
class Derived : public Base {
    std::string child_string;
    public:
    Derived() : Base(), child_string("child") {
        std::cout << "child class" << std::endl;
        parent_string = "change"; // parent_string 이 pivate 이면 오류
    }
    void what() { std::cout << child_string << std::endl; }
};
```

