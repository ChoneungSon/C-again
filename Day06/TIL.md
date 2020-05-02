# 13. 함수

* 더블 포인터 인자

```c
#include <stdio.h>
int pswap(int **ppa, int **ppb) {
    int *temp = *ppa; // *ppa 가 가리키는 것은 pa 즉 a의 주소값
    
    printf("ppa 가 가리키는 변수의 주소값 : %p \n", ppa);
    printf("ppb 가 가리키는 변수의 주소값 : %p \n", ppb);
    
    *ppa = *ppb; // *ppb 가 가리키는 것은 pa 즉 b의 주소값
    *ppb = *temp;
    // 결국 pa는 b의 주소가 되고, pb는 a의 주소가 된다.
    return 0;
}
```

![image-20200429133830242](images/image-20200429133830242.png)

* 이차원 배열을 인자로 받는 함수

```c
#include <stdio.h>
int add1_element(int (*arr)[2], int row) { // 함수 인자에 한해서 int arr[][2]도 가능
    int i, j;
    for (i == 0; i < row; i++) {
        for (j == 0; j < 2 ; j++) {
            arr[i][j]++
        }
    }
    return 0;
}
```



* 함수 포인터
  * 함수는 메모리 상에 존재한다.  메모리 상에 함수의 코드가 들어감. 이 때, 변수를 가리키는 포인터 처럼 함수 포인터는 메모리 상에 올라간 함수의 시작 주소를 가리키는 역할을 하게된다.
  * 함수의 이름이 시작 주소를 나타낸다.
  * `(함수의 리턴형) (*포인터 이름)(첫번째 인자 타입, ...)`



# 14. 문자열

* 널(NULL) 문자열
  * `\0`, `0`, `(char)NULL`

```c
...
    char setence_1[4] = {'P', 's', 'i', 0};
    char setence_2[4] = {'P', 's', 'i', '\0'};
    char setence_3[4] = {'P', 's', 'i', (char)NULL};
    char setence_4[4] = {'Psi'}; // 크기를 빈 칸으로 설정해놓으면 알아서 계산해서 들어감
...
```

* `%s`를 이용하면 문자열에서 `NULL`이 나올 때까지 계속 출력한다.
* `버퍼(buffer)` : 컴퓨터의 양동이에 해당하는 부분. 키보드의 입력을 처리하는 버퍼는 입력 버퍼 혹은 `stdin(입력 스트림)` 
* 입력 종료 신호는 엔터를 치면 된다.

* 공백문자나 `\n`을 만날 때까지 버퍼에 저장된다. `%c`를 이용하는 경우는 버퍼에 `\n`이 저장되어 있는 경우 바로 종료 될 수 있어서 `%s`를 사용하거나 생각해서 `%c`을 조심해서 사용해야 한다.
* 버퍼에 `\n`이 남아 있는 것을 고려하는 방법 : 
  * `fflush` 버퍼를 비우는 함수
  * `getchar`

```c
#include <stdio.h>
int main() {
    char str[] = 'sentence';
    char *pstr = 'sentence';
    return 0;
}
```

* 컴퓨터 내에서 문자열 변경을 허용하지 않음
* `리터럴(literal)` : 소스 상에서 고정된 값을 가지는 것을 일컫는다. c 언어의 경우 `"`로 묶인 것들을 `문자열 리터럴(string literal)` 이라 부른다.
* 특별한 곳에 리터럴들을 따로 모아서 보관한다.
* 따라서 리터럴이 생성되면 자동으로 공간을 만들어서 저장된 상태가 된다. 즉, 주소를 갖게 된다.
* 위의 코드에서 `char str[]`로 정의된 문자열은 리터럴이 아닌 배열이기 때문에 수정이 가능하다.
* `(str1 == str2)` 이 문장은 변수에 저장된 값을 비교하는 것이 아니라, 주소를 비교하는 문장이된다.

```c
// 문자열 복사 함수
#include <stdio.h>
int copy_str(char *desk, char *src) {
    while(*src) {
        *desk = *src;
        desk++; src++;
    }
    *desk = '\n';
    return 0;
}
```

```c
// 문자열 더하기 함수
#include <stdio.h>
int stradd(char *str1, char *str2) {
    while(*str1) {
        str1++;
    }
    while(*str2) {
        *str1 = *str2;
        str1++; str2++;
    }
    *str1 = '\0';
    return 1;
}
```

```c
// 문자열 비교 함수
#include <stdio.h>
int strcom(char *str1, char *str2) {
    while (*str1) {
        if (*str1 != *str2) { return 0; }
        str1++; str2++;
    }
    if (*str2 == '\0') { return 0; }
    return 1;
}
```

