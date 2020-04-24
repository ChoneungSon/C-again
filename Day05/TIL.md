# 함수

* `main` 함수
  * 프로그램을 실행할 때 컴퓨터가 먼저 찾는 함수
  * 리턴하는 데이터는 운영체제가 받아드림

```c
// 집어넣은 값의 4를 더해서 반환하는 함수
#include <stdio.h>
int magicbox(int num){
    return num+4;
}
int main() {
    int num;
    scanf("더할 값을 선택하세오 : %d", &num);
    printf("%d 에 4를 더한 값은 %d 입니다.", num, magicbox(num));
    return 0;
}
```

