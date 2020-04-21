# 12. 포인터

* 특정한 데이터가 저장된 주소값을 보관하는 변수
* 포인터의 정의
  * `(포인터에 주소값이 저장되는 데이터의 형) *(포인터의 이름);`
  * `(포인터에 주소값이 저장되는 데이터의 형)* (포인터의 이름);`

```c
int* p;
int *p;
```

```c
/* & 연산자 */
#include <stdio.h>
int main() {
    int a;
    a = 2;
    
    print("%p \n", &a);
    return 0;
}
```

```bash
0X7fff80505b64
```

* `&a`의 값을 `%p` 16진수 형태로 출력하라고 명령
* `*` 연산자 : 포인터를 포인터에 저장된 주소값에 위치한 데이터로 생각

```c
/* * 연산자 */
#include <stdio.h>
int main() {
    int *p;
    int a;
    
    p = &a;
    a = 2;
    
    printf("a의 값 : %d\n", a);
    printf("*p의 값 : %p\n", *p);
    return 0;
}
```

```bash
a의 값 : 2
*p의 값 : 2
```



```c
/* * 연산자 */
#include <stdio.h>
int main() {
    int *p;
    int a;
    
    p = &a;
    *p = 3;
    
    printf("a의 값 : %d\n", a);
    printf("*p의 값 : %p\n", *p);
    return 0;
}
```

```bash
a의 값 : 3
*p의 값 : 3
```

* 포인터에는 변수가 차지하는 모든 메모리 주소들의 위치가 들어 있는 것이 아니라 **시작주소**만 들어가 있다.

```c
/* 상수 포인터 */
#include <stdio.h>
int main() {
    int a;
    int b;
    const int* pa = &a;
    
    *pa = 3; // 올바르지 않은 문장
    pa = &b; // 올바른 문장
    return 0;
}
```

* 포인

