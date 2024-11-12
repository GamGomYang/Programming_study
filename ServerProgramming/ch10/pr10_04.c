// 1번 문제 man을 치면 메뉴얼이 나오는데 그냥 4줄 나오도록만 출력
// 3번 문제
// 4번문제 스레드이용한 구구단 짤리지 않도록 출력

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex;

void *print_multiplication_table(void *arg) {
    int num = *(int *)arg;

    pthread_mutex_lock(&mutex);
    for (int i = 1; i <= 9; i++) {
        printf("%d * %d = %d\n", num, i, num * i);
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[8];
    int nums[8];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 8; i++) {
        nums[i] = i + 2;
        pthread_create(&threads[i], NULL, print_multiplication_table, &nums[i]);
    }

    for (int i = 0; i < 8; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
