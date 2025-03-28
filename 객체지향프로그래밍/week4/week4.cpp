// // inline 함수의 사용

// //매크로 함수 와 달리 타입 체크가 가능하다.
// #include <iostream>
// using namespace std;

// inline int odd(int x) {

//     return (x % 2);
// }

// int main() {

//     int sum = 0;
//     for (int i = 0; i < 10000; i++) {

//         if (odd(i))
//             sum += i;
//     }

//     cout << sum;

//     // 디폴트매개변수 자동형변환 시험에 나올 수 있다.
// /

// #include <iostream>
// using namespace std;

// void myswap(int &a, int &b) {

//     int tmp;
//     tmp = a;
//     a = b;
//     b = tmp;
// }

// void myswap(double &a, double &b) {

//     double tmp;
//     tmp = a;
//     a = b;
//     b = tmp;
// }

// int main() {

//     int a = 4;
//     int b = 5;

//     myswap(a, b);
//     cout << a << '\t' << b << endl;

//     double c = 0.3, d = 12.5;

//     myswap(c, d);
//     cout << c << '\t' << d << endl;
// }
