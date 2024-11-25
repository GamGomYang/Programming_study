#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

void selection_sort(int list[], int n);
int binary_search(int list[], int n, int key);

int main(void) {
    int key;
    int numbers[SIZE] = {30, 13, 22, 45, 6, 11, 2, 29, 20, 18};

    // 배열을 선택 정렬로 정렬합니다.
    // 선택정렬함수 선언후 호출하여 정렬시작
    selection_sort(numbers, SIZE);

    // 선택정렬후 배열[2,6,11,13,18,20,22,29,30]

    // 정렬된 배열을 출력합니다.
    printf("정렬된 배열: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // 사용자에게 탐색할 값을 입력받습니다.
    printf("탐색할 값을 입력하시오: ");
    scanf("%d", &key);

    // 이진 탐색을 수행하고 결과를 출력합니다.
    int result = binary_search(numbers, SIZE, key);
    if (result != -1) {
        printf("탐색 결과= %d\n", result);
    } else {
        printf("탐색실패\n");
    }
    return 0;
}

// 선택 정렬 함수 완성
void selection_sort(int list[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (list[j] < list[min_index]) {
                min_index = j;
            }
        }
        // 숫자 순서 바꾸기
        int temp = list[i];
        list[i] = list[min_index];
        list[min_index] = temp;
        /* //정렬 검증 출력
           printf("sort %d = ", i + 1);
           printf("[");
           for (int k = 0; k < SIZE; k++) {
               printf("%d ", list[k]);
           }
           printf("]");
           printf("\n\n"); */
    }
}

// 이진 탐색 함수 완성
// 함수 인자 : 배열, 배열의 크기, 키값
int binary_search(int list[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (list[mid] == key) {
            return mid; // 이진탐색 성공
        } else if (list[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}
