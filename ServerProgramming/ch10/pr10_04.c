//시험 : 코드가 주어졌을때 잘못된부분찾기
// 명령어 자주 타이핑 해보기
// 1번 문제 man을 치면 메뉴얼이 나오는데 그냥 4줄 나오도록만 출력
// 3번 문제 
// 4번문제 스레드이용한 구구단 짤리지 않도록 출력

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;

void* print_gugudan(void* arg) {
    int dan = *(int*)arg;
    pthread_mutex_lock(&mutex);

    for (int i = 1; i <= 9; i++) {
        printf("%d x %d = %d\n", dan, i, dan * i);
    }

    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[8];
    int dan[8];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 8; i++) {
        dan[i] = i + 2;
        pthread_create(&threads[i], NULL, print_gugudan, &dan[i]);
    }

    for (int i = 0; i < 8; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}
