# 12. 포인터

```c
#include <stdio.h>
int main() {
    int arr[3] = {1, 2, 3};
    int* parr;
    
    parr = arr; // 둘다 같은 표현이다.
    parr = &arr[0];
    
    return 0;
}
```

* 반복문을 돌릴 때 포인터를 이용하는 법

```c
#include <stdio.h>
int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* parr; int sum = 0;
    parr = arr;
    
    while (parr-arr < 10):{ // 이것 때문에 포인터간의 뺄셈이 중요하다 한듯
        sum += *parr;
        parr++;
    }
    
    return 0;
}
```

* 하지만 아래와 같은 코드는 오류가 난다.

```c
#include <stdio.h>
int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    arr++; // arr의 이름에 주소가 들어간 것일 뿐, arr가 포인터를 의미하지 않기 때문에 오류가 발생한다.
    return 0;
}
```

* `int **p` : int 를 가리키는 **포인터의 포인터**

```c
// 각 줄에 나열된 값들은 같은 값이다.
#include <stdio.h>
int main() {
    int a = 3; int *pa; int **ppa;
    pa = &a; ppa = &pa;
    
    // a == *pa == **ppa;
    // &a == pa == *ppa;
    // &pa == ppa;
    
    return 0;
}
```



```c
#include <stdio.h>
int main() {
    int arr[3] = {1, 2, 3};
    int (*parr)[3] = &arr; // (parr + 3) = &arr
    
    printf("arr[1] : %d \n", arr[1]); // 2
    printf("parr[1] : &d \n", (*parr)[1]); // 2, 꼭 (*parr)의 형태로 사용해야 한다.
    
    return 0;
}
```

* `arr` 크기가 3인 배열이기 때문에 `&arr` 를 보관할 포인터는 **크기가 3인 배열을 가리키는 포인터**가 되어야 한다. 결국엔 위의 코드의 결과는 arr와 parr가 같아진다.

* B 언어에서는 배열의 각 자리에 요소가 위치한 포인터가 들어가는 방식 이었지만, 보다 효율적으로 메모리를 운용하기 위해 현재와 같이 첫번째 원소의 주소값만 포인터에 저장하는 방식으로 바뀌었다.

```c
#include <stdio.h>
int main() {
    int arr[2][3];
    
    // arr[0] == &arr[0][0]; arr[i]는 arr[i][0]의 주소 값을 참조한다. 1차원 배열과 비슷하게
    // arr[1] == &arr[1][0];
    
    return 0;
}
```

```c
#include <stdio.h>
int main() {
    int arr[2][3] = {1, 2, 3, 4, 5, 6};
    printf("전체 크기 : %d \n", sizeof(arr)); // >> 24
    printf("열의 크기 : %d \n", sizeof(arr[0]) / sizeof(arr[0][0])); // >> 12 / 4
    printf("행의 크기 : %d \n", sizeof(arr) / sizeof(arr[0])); // >> 24 / 12
    return 0;
}
```

* `int**` 는 형이 될 수 없다. 형이 될 수 있다면, 포인터가 배열의 이름을 가리키면 배열의 원소에 자유롭게 접근할 수 있어야만 한다. 이차원 배열에 접근하기 위해서는 열의 크기 정보를 알아야한다.  `int** parr = arr`일 때, `parr`는 `arr[0][0]`의 주소를 참조하기 때문에, 열의 크기 정보를 알 수가 없다. 

```c
#include <stdio.h>
int main() {
    int arr[2][3] = {1, 2, 3, 4, 5, 6};
    int* parr = arr;
    
    printf("parr : %p, parr + 1 : %p", parr, parr+1); // 12 차이난다.
    return 0;
}
```

```c
#include <stdio.h>
int main() {
    int arr[2][3] = {{1,2,3}, {4,5,6}};
    int brr[10][3];
    int crr[2][5];
    
    int (*parr)[3] = &arr; // parr는 원소가 2개인 배열을 참조하고, 각각의 원소들의 길이는 3인 것으로 해석이 가능하다.
    
    parr = arr; // parr가 참조하는 원소의 길이가 3 이므로 ok
    parr = brr; // 위와 같음
    parr = crr; // parr가 참조하는 원소의 길이가 5 이므로 오류 발생
    
    return 0;
}
```

* 포인터 배열

```c
#include <stdio.h>
int main() {
    int* arr[3]; // int* 형 변수를 받는 배열을 정의 배열의 원소들을 포인터가 저장된다.
    
    return 0;
}
```

