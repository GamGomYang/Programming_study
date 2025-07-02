#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
