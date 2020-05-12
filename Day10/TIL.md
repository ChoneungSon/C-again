# 매크로 함수

```c
#define square(x) x*x;
// #define 함수이름(인자) 식
// 그냥 함수는 값을 반환하지만
// 매크로 함수는 함수가 실행될 자리에 식을 대체시켜 컴파일 한다.
square(4 + 1); // >> 4+1 * 4+1 이런 식으로 돼버림

#define square(x) (x)*(x); // 따라서 함수를 정의할 때 이렇게 괄호 정의가 필요하다
    
#define PrintVar(var) printf(#var "\n");
// 위의 함수에서 #var는 var라는 변수를 문자열로 치환해준다. 
// 따라서 PrintVar(a) = printf("a\n") 가 된다.

#define PrinttwoVar(var1, var2) printf(var1##var2 "\n");
// ##은 두 변수를 이어주는 문자열을 만든다.
// 따라서 PrinttwoVar(a, b) = print("ab\n") 이 된다.
```



# 인라인 함수

* 매크로 함수처럼 식을 대체시켜 컴파일 하게 한다. 하지만 괄호를 생각할 필요가 없음.

```c
__inline //으로 시작하여 일반 함수처럼 정의하면 된다.
```



# typeof

```c
typeof struct HUMAN Human;
// typeof (바꾸기 전 타입) (대체할 문구)

typeof int CAL_TYPE;
// int의 크기가 각각 다른 컴퓨터에 이렇게 정의하면 알아서 int에 해당하는 타입이 CAL_TYPE으로 대체된다.
```

