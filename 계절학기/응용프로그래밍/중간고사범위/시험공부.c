#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*

NULL 문자 (\0)
문자열의 끝을 나타낸다.


*/

// #include <stdio.h>

// int main(void) {

//     char test_string[10] = "helloworld";
//     int i = 0;
//     while (test_string[i] != '\0') {
//         printf("%c", test_string[i]);
//         i++;
//     }

//     return 0;
// }

// #include <stdio.h>

// int main(void) {

//     char str1[6] = "seoul";
//     char str2[3] = {'i', 's', '\0'};
//     char str3[] = "the capital city of korea";
//     printf("%s %s %s", str1, str2, str3);
// }

// 문자열 복사 예제

// #include <stdio.h>

// int main(void) {

//     char str1[] = "hello world";

//     char dest[100];

//     printf("원본 문자열 = %s\n", str1);

//     for (int i = 0; str1[i] != '\0'; i++) {

//         dest[i] = str1[i];
//     }

//     printf("copy = %s", dest);
// }

// strcpy를 사용한 문자열 복사
// 라이브러리 함수인 strcpy를 사용하여 문자열을 문자배열로 복사 strcpy(str1, "world");
//** 문자열 변경방법에는 strcpy도 있다.
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(void) {

//     char str1[] = "hello";
//     printf(" %s \n", str1);

//     strcpy(str1, "world");
//     printf(" %s", str1);
// }

// 텍스트세그먼트에 저장되어지고 문자열 배열은 스택에 저장되어짐
// 문자열 배열은 읽기 쓰기가 가능하지만 텍스트 세그먼트는 읽기만 가능
// 만약에 p를 바꿔버리면 그냥 텍스트 세그먼트에서 대상을 바꿔버린다.
// 고로 p를 바꿔버리는건 되지만 수정은 안된다 왜냐하면 텍스트 세그먼트는 읽기만 가능하니까

// 예시 하나 만들어보기

// #include <stdio.h>

// int main(void) {

//     char *p = "hello world";
//     printf("%s\n", p);
//     p = "lets get it";
//     printf("%s", p);
//     return 0;
// }

// getchar putchar사용해보기

// #include <stdio.h>
// #include <string.h>

// int main(void) {

//     int ch;
//     while ((ch = getchar()) != EOF) {
//         putchar(ch);
//     }

//     return 0;

//     // getchar 문자 하나 입력받기
//     // putchar 문자 하나 출력하기
// }

// #include <stdio.h>

// int main(void) {

//     char name[100];
//     char address[100];

//     printf("이름을 입력하세요 :");

//     scanf("%s", name);

//     printf("현재 거주하는 주소를 입력하시오");

//     scanf("%s", address);
//     // scanf 는 공백 전까지만 읽는다 즉 서울시 종로구 라고 하면 서울시만 읽는다.
//     // 문자열을 읽게 하기 위해서는 puts를 사용하는것이 바람직gets

//     printf("안녕하세요 %s 에 사시는 %s 씨", address, name);

//     return 0;
// }

// gets_s 와 puts를 사용해서 문자열 출력해보기

// #include <stdio.h>
// #include <string.h>

// int main(void) {

//     char name[100];
//     char address[100];

//     printf(" 이름 입력 : ");
//     fgets(name, sizeof(name), stdin);

//     printf(" 주소 입력 : ");
//     fgets(address, sizeof(address), stdin);

//     printf("안녕하세요 %s에 사시는 %s씨", address, name);

//     return 0;
// }

// strcpy 와 strcat 사용 예제

// #include <stdio.h>
// #include <string.h>

// int main(void) {

//     char string[80];
//     strcpy(string, "hello world");
//     strcat(string, "my name is strcat\n");
//     strcat(string, " strcpy strcat is funny function isn't it??");

//     printf("%s", string);

//     return 0;
// }
// strcmp 에서 0보다 작으면 s1이 s2보다 앞에 있다. 모든것이 s1기준으로 작동되어짐

// 특정 문자 검색해보기
// #include <stdio.h>
// #include <string.h>
// int main(void) {
//     char s[] = "language";

//     char c = 'g';

//     char *p;
//     int loc;

//     p = strchr(s, c);

//     if (p == NULL) {
//         printf("발견 되어지지 않았슴둥 \n");
//     } else {

//         loc = (int)(p - s);
//         printf("%s에서 첫번째 %c 가 %d에서 발견되었음", s, c, loc);
//     }
//}
// 문자 검색은 strchr 문자검색은 strstr로 사용

// #include <stdio.h>
// #include <string.h>

// int main(void) {

//     char s[] = "hello world";

//     char c[] = "hello";

//     char *p;

//     p = strstr(s, c);

//     if (p == NULL) {
//         printf("발견되어지지 않았음\n");
//     } else {

//         int loc = (int)(p - c);

//         printf("%s 에서 %s가 %d에서 발견되었음", s, c, loc);
//         }

//     return 0;
// }

// 문자열 토큰 분리 strtok;

// 소수 판정 함수

// int is_prime(int n) {

//     int divider, to;

//     to = (int)sqrt((double)n);

//     while (divider <= to) {
//         if (n % divider == 0) {
//             return 0;
//         }
//         divider++;
//     }
//     return 1;
// }

// 에라토스테네스 체 이용 소수 출력

// int main() {

//     int number;
//     printf("정수 입력");

//     scanf("%d", &number);

//     int array[number + 1];

//     for (int i = 0; i < number; i++) {

//         array[i] = 0;
//     }

//     array[0] = array[1] = 1;

//     int to = (int)sqrt((double)number);

//     for (int i = 2; i <= to; i++) {
//         if (array[i] == 0) {
//             for (int k = i * i; k <= number; k += i) {
//                 array[k] = 1;
//             }
//         }
//     }
// }

// 배열을 난수로 채우기

// #define SIZE 5
// int main(void) {

//     int i;
//     int score[SIZE];
//     srand((unsigned)time(NULL));
//     for (int i = 0; i < SIZE; i++) {

//         score[i] = rand() % 100;
//     }

//     for (int i = 0; i < SIZE; i++) {

//         printf("%d\n", score[i]);
//     }

//     return 0;
// }

// srand((unsigned)time(NULL));
// rand()%100;

// #include <stdio.h>

// #define SIZE 5

// int get_average(int score[], int n);

// int main(void) {

//     int score[SIZE] = {1, 2, 3, 4, 5};

//     int avg;

//     avg = get_average(score, SIZE);

//     printf(" 평균 : %d", avg);

//     return 0;
// }

// int get_average(int scores[], int n) {

//     int i = 0;
//     int sum = 0;

//     for (int i = 0; i < n; i++) {

//         sum += scores[i];
//     }

//     return sum / n;
// }

// 배열은 주소가 전달 포인터 형식으로 전달 안해도 된다.

// int alphabet[26];

// int main(void) {

//     char ch;
//     int n;
//     FILE *fp = fopen("sample.txt", "r");

//     for (int i = 0; i < 26; i++) {
//         alphabet[i] = 0;
//     }

//     while (!feof(fp)) {
//         ch = fgetc(fp);
//         if (isupper(ch)) {
//             alphabet[ch - 'A']++;
//         } else if (islower(ch)) {
//             alphabet[ch - 'a']++;
//         }
//     }
//     fclose(fp);

//     for (int i = 0; i < 26; i++) {

//         printf("%c  : %d\t", n + 'A', alphabet[i]);
//     }

//     return 0;
// }

// #define MAX_ARRAY 100

// char *pstrarray[MAX_ARRAY];

// int nword;

// void get_word() {

//     char buffer[100];

//     nword = 0;

//     while (nword < MAX_ARRAY) {

//         gets(buffer);
//         if (strcmp(buffer, "") == 0) {
//             break;
//         }
//         pstrarray[nword] = malloc(strlen(buffer) + 1);
//         srtcpy(pstrarray[nword], buffer);
//         nword++;
//     }
// }

// int main(void) {

//     int i = 10;

//     double f = 12.3;
//     int *pi = NULL;
//     double *pf = NULL;
//     pi = &i;
//     pf = &f;

//     printf("%p %p \n ", pi, &i);
//     printf("%p %p", pf, &f);

//     return 0;
// }

// 포인터 연산 증감연산

// int main(void) {

//     char *pc;
//     int *pi;
//     double *pf;

//     pc = (char *)10000;
//     pi = (int *)10000;
//     pf = (double *)10000;

//     printf()
// }

// #include <stdio.h>
// int main(void) {
//     char *pc;
//     int *pi;
//     double *pd;
//     pc = (char *)10000;
//     pi = (int *)10000;
//     pd = (double *)10000;
//     printf(" pc=%u,  pc+1=%u,  pc+2= %u\n", pc, pc + 1, pc + 2);
//     printf(" pi=%u,  pi+1=%u,  pi+2= %u\n", pi, pi + 1, pi + 2);
//     printf(" pd=%u,  pd+1=%u,  pd+2= %u\n", pd, pd + 1, pd + 2);
//     return 0;
// }

// #include <stdio.h>
// int main(void) {
//     int i = 10;
//     int *pi = &i;
//     printf("i = %d,  pi = %p\n", i, pi);
//     (*pi)++;
//     printf("i = %d,  pi = %p\n", i, pi);
//     *pi++;
//     printf("i = %d,  pi = %p\n", i, pi);
//     return 0;
// }

// #include <stdio.h>
// int main(void) {
//     int a[] = {10, 20, 30, 40, 50};
//     printf("a = %u\n", a + 0);
//     printf("a + 1 = %u\n", a + 1);
//     printf("*a = %d\n", *a);
//     printf("*(a+1) = %d\n", *(a + 1));
//     return 0;
// }

// 이중 포인터와 함수

// void set_pointer(char **q);
// int main(void) {

//     char *p;

//     set_pointer(&p); // 주소를 넘긴다.

//     printf("오늘의 격언 %s", p);

//     return 0;
// }

// void set_pointer(char **q) {
//     *q = "all that glister is not gold";
// }

// 포인터 계산

// 문자열도 포인터로 나타낼 수 있다.
//  int main(void) {

//     int i, n;

//     char *fruits[] = {
//         "apple",
//         "stroberry",
//         "pineapple"};

//     n = sizeof(fruits) / sizeof(fruits[0]);

//     for (int i = 0; i < n; i++) {

//         printf("%s\n", fruits[i]);
//     }
// }

// 함수 포인터

// int add(int a, int b) {
//     return a + b;
// }
// int sub(int a, int b) {
//     return a - b;
// }

// int main(void) {

//     int result;

//     int (*pf)(int, int);

//     pf = add;
//     result = pf(10, 20);

//     printf("%d\n", result);

//     pf = sub;
//     result = pf(10, 20);

//     printf("%d \n", result);

//     return 0;
// }

// 함수 포인터 선언방법 int (*pf)(int, int);

// pf = add;
// pf = sub;

// result = pf(10, 20);

// 이렇게

// 포인터 배열처럼 함수 포인터 배열도 있음

// int (*pf[5])(int, int);

// int main(void) {

//     int choice = 0;
//     int result = 0;
//     int x, y;

//     int (*pf[4])(int, int) = {add, sub, mul, div};

//     while(1){

//     }
// }

// double f1(double k);
// double f2(double k);
// double fomula(double (*fp)(double), int n);

// int main(void) {
//     printf("%f \n ", fomula(f1, 10));
//     printf("%f \n", fomula(f2, 10));

//     return 0;
// }

// double f1(double k) {
//     return 1 / k;
// }

// double f2(double k) {
//     return cos(k);
// }

// int main(int argc, char *argv[]) {
//     double mile, km;

//     if (argc != 2) {
//         perror("argument");
//         return 1;
//     }

//     mile = atof(argv[1]);

//     km = 1.609 * mile;

//     printf("%d\n", km);

//     return 0;
// }

// FILE *fp;
// fp = fopen("test.txt", "r");
// rwa a - strcat 같은거라고 생각

// int main(void) {

//     FILE *fp = NULL;
//     fp = fopen("sample.txt", "r");

//     if (fp == NULL) {
//         return 1;
//     }

//     fputc('a', fp);
//     fputc('b', fp);

//     fclose(fp);

//     return 0;
// }

// int main(void) {
//     FILE *fp1, *fp2;

//     char buffer[100];
//     char file1[100];
//     char file2[100];

//     fopen("sample.txt", "r");
//     fopen("asample.txt", "w");

//     while (fgets(buffer, 100, fp1) != NULL) {
//         fputs(buffer, fp2);
//     }

//     fclose(fp1);
//     fclose(fp2);
// }

// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {

//     FILE *fp;
//     char name[100];

//     int number;
//     float score, total = 0;

//     fp = fopen("sample.txt", "w");
//     if (fp == NULL) {
//         fprintf(stderr, "성적 파일을 읽을 수 없음 \n");
//         exit(1);
//     }

//     while (1) {
//         printf("학번 성적 이름 입력 \n");

//         scanf("%d %s %f", &number, name, &score);

//         fprintf(fp, "%d %s %.2f\n", number, name, score);
//     }

//     fclose(fp);

//     fp = fopen("sample.txt", "r");
//     fclose(fp);
// }

// #define SIZE 5
// int main(void) {

//     int buffer[SIZE] = {10, 20, 30, 40, 50};
//     FILE *fp = NULL;
//     fp = fopen("sample.bin", "wb");

//     if (fp == NULL) {
//         perror("error");
//         return 1;
//     }

//     fwirte(buffer, sizeof(int), SIZE, fp);

//     fclose(fp);

//     fp = fopen("sample.bin", "rb");

//     fread(buffer, sizeof(int), SIZE, fp);

//     fclose(fp);

//     return 0;
// }

// int main(void) {

//     FILE *src_file, *dst_file;

//     char filename[100];

//     char buffer[1024];
//     int r_count;

//     src_file = fopen("flower.jpg", "rb");
//     dst_file = fopen("a_sample.jpg", "wb");

//     if (src_file == NULL || dst_file == NULL) {
//         perror("errer");

//         return 1;
//     }

//     while ((r_count = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
//         int w_count = fwrite(buffer, 1, r_count, dst_file);
//         if (w_count < 0) {
//             perror("error");
//             return 1;
//         }

//     }
// }

// 배열에 변수는 안된다. #define 정의만 가능 (기호상수)

// #define SIZE 10

// int main(void) {

//     int price[SIZE] = {0};

//     int i;
//     int min = 100;

//     srand((unsigned)time(NULL));

//     for (i = 0; i < SIZE; i++) {

//         price[i] = (rand() % 100) + 1;

//         printf("%-3d", price[i]);
//     }

//     printf("\n");

//     for (i = 0; i < SIZE; i++) {

//         if (price[i] < min) {
//             min = price[i];
//         }
//     }

//     printf("minimun = %d", min);

//     return 0;
// }

// selection sort
// #define SIZE 10

// int main(void) {
//     int minimum;

//     int list[SIZE];

//     srand((unsigned)time(NULL));

//     for (int i = 0; i < SIZE; i++) {
//         list[i] = rand() % 100;
//     }

//     for (int i = 0; i < SIZE; i++) {
//         int least = i;

//         for (int k = i + 1; k < SIZE; k++) {
//             if (list[k] < list[least]) {
//                 least = k;
//             }
//         }
//         int temp = list[i];
//         list[i] = list[least];
//         list[least] = temp;
//     }

//     for (int i = 0; i < SIZE; i++) {
//         printf("%-3d", list[i]);
//     }

//     return 0;
// }

// #define MAX 100
// #define SIZE 10
// void print_array(int array[]);
// void selection_sort(int array[]);
// void generate_random(int array[]);

// int main(void) {

//     int n, r;

//     srand(time(NULL));

//     int data[SIZE] = {0};

//     generate_random(data);

//     print_array(data);
//     printf("\n");
//     selection_sort(data);
//     print_array(data);

//     return 0;
// }

// void selection_sort(int array[]) {
//     for (int i = 0; i < SIZE; i++) {
//         int minimum = i;
//         for (int k = i + 1; k < SIZE; k++) {
//             if (array[k] < array[minimum]) {
//                 minimum = k;
//             }
//         }
//         int temp = array[i];
//         array[i] = array[minimum];
//         array[minimum] = temp;
//     }
// }

// void generate_random(int array[]) {

//     for (int n = 0; n < SIZE; n++) {

//         array[n] = (rand() % 100) + 1;
//     }
// }

// void print_array(int array[]) {

//     for (int i = 0; i < SIZE; i++) {
//         printf("%d  ", array[i]);
//     }
// }

// void generate_array(int array[], int size);
// void print_array(int array[], int size);
// void bubble_sort(int array[], int size);

// int main(int argc, char *argv[]) {
//     int *data;
//     int size;

//     srand(time(NULL));

//     printf("size");
//     scanf("%d", &size);

//     data = (int *)malloc(sizeof(int) * size);
//     generate_array(data, size);
//     print_array(data, size);

//     printf("\n");

//     bubble_sort(data, size);
//     print_array(data, size);
// }

// void generate_array(int array[], int size) {

//     for (int i = 0; i < size; i++) {

//         array[i] = (rand() % 100) + 1;
//     }
// }

// void print_array(int array[], int size) {
//     for (int i = 0; i < size; i++) {

//         printf("%d  ", array[i]);
//     }
// }

// void bubble_sort(int array[], int size) {

//     for (int i = 0; i < size - 1; i++) {
//         for (int k = 0; k < size - i - 1; k++) {

//             if (array[k] > array[k + 1]) {
//                 int temp = array[k];
//                 array[k] = array[k + 1];
//                 array[k + 1] = temp;
//             }
//         }
//     }
// }

// struct student {
//     int number;
//     char name[20];
//     double grade;
// };

// int main(void) {

//     struct student s1 = {123, "kim", 3};
//     struct student *p;

//     p = &s1;

//     printf("%f", (*p).grade);
// }

// 포인터 멤버로 가지는 구조체

// struct student {
//     int number;
//     char name[20];
//     double grade;
// };

// struct letgo {
//     int letgo;
//     struct student *p;
// };

// int main(void) {

//     struct student stu1 = {202, "kim", 3};

//     struct letgo let1 = {123};

//     let1.p = &stu1;

//     printf("%d", let1.p->number);

//     return 0;
// }
// int main(void) {

//     char filename[100];
//     int i = 0;

//     for (int i = 0; i < 6; i++) {

//         sprintf(filename, "image%d.jpg", i);
//         printf("%s \n", filename);
//     }

//     return 0;
// }

// int main() {
//     char str[] = "this is ,a sample programming";

//     char *token;

//     token = strtok(str, " ,.");
//     while (pch != NULL) {
//         printf("%s\n", token);
//         token = strtok(NULL, " ,.");
//     }

//     return 0;
// }

// void eratos(int number, char array[]) {
//     int n, m, to, last, index;

//     to = (int)sqrt((double)number);
//     for (n = 2; n <= to; n++) {
//         last = number / n;
//         for (m = 2; m <= last; m++) {
//             index = n * m;
//             array[index] = 1;
//         }
//     }
// }

// void eratos(int number, char array[]) {
//     int n, m, to, last, index;

//     to = (int)sqrt((double)number);
//     for (n = 2; n <= to; n++) {

//         last = number / n;
//         for (m = 2; m <= last; m++) {
//             index = n * m;
//             array[index] = 1;
//         }
//     }
// }

// 동적 배열 할당

// int *array = (int *)malloc(sizeof(int) * 5);
// int *array2 = (int *)calloc(5, sizeof(int));

// free(array);
// free(array2);

// void read_file() {

//     char buffer[256];

//     FILE *fp = fopen("sample.txt", "r");

//     if (fp == NULL) {
//         perror("error");
//         return 1;
//     }

//     while (fgets(buffer, 255, fp) != NULL) {

//         char *token = strtok(buffer, " ,.?\n\t");
//         while (token != NULL) {
//         }
//     }
// }

// strcpy(dest, src);
// strcat(dest, src);

// strcmp(s1, s2);
// strchr(str, ch);
// strstr(str, substr);

// fgets(str, size, stdin);
// gets_s;
// puts(str);

// getchar putchar;
// gets puts;
// fgets fputs;

// srand(time(NULL));

// void func(char **tp);
// p -> grade;

// stu.p -> grade
// stu.p = &cli;

// stu.*p.grade