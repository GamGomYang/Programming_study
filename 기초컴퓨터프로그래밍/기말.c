/*#include <stdio.h>

void selectionsort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        int min = i;

        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[min]) {
                min = j;
            }

            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void binarysearch(int arr[], int n, int key) {

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

        return -1;
    }
}

int main(void) {
}

#include <stdio.h>

int main() {

    int num = 10;
    int *ptr = &num;

    printf("value: %d", *ptr);
    printf("adress %p", ptr);

    //* p = vlaue p = adress
}



#include <stdio.h>

int main(void) {

    int arr[] = {10, 20, 30};

    int *p = arr;

    int v1 = ++*p;   // 11
    int v2 = *++p;   // 20
    int v3 = *p++;   // 20 -> 30;
    int v5 = (*p)++; // 30 -> 31

    printf(" %d %d %d %d", v1, v2, v3, v5);

    return 0;
}

#include <stdio.h>

int main(void) {

    int a = 100;
    int b = 200;

    printf(" %d %d ", a, b);

    swap(&a, &b); // 함수에 수를 넣을 때는 &기호 붙이기

    printf("%d %d ", a, b);

    return 0;
}

void swap(int *px, int *py) {
    // 함수 선언시에는 포인터 * 표기 하기

    int tmp;

    tmp = *px;
    *px = *py;
    *py = tmp;
}


11장 p17 안나왔다고하셨음
p18 별이 붙었는지 안붙었는지 확인후 판단하기

get_s 안나옴
put은 한번 보기
islower toupper를 사용하기 위해서는 #include<cype.h> 헤더파일을 include해야한다.

p43. 문자열 처리함수
strlen strcpy strcat strcmp 이 4가지를 유심히 알아보자
strcmp 비교에 대한 결과에대해 유심히 알아보기

p43까지가 시험범위임
-> 아래의 strcpy strcat등 예제코드 살펴보기
->p.50까지 보면 됨


#include <stdio.h>

int main(void) {

    int i = 300;
    int *p = NULL;

    p = &i;

    printf("%p", &i);
}


#include <stdio.h>

void sub(int b[], int n);
int main(void) {

    int a[3] = {1, 2, 3};

    sub(a, 3);
}

void sub(int b[], int n) {

    b[0] = 1;
    b[1] = 3;
    b[2] = 5;
}


#include <stdio.h>

#define SIZE 5

void brighten_image(int imega[][SIZE]) {

    int r, c;
    int *p;
    p = &image[0][0];
    // 결국 이차원배열을 포인터로 올리기

    int *p;
    p = &image[0][0];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            *p += 10;
            p++;
        }
    }
}


getchar 사용법
while((ch = getchar())!= EOF){
    putchar(ch);
}

*/