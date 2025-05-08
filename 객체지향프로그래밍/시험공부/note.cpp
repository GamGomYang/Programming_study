// #include <iostream>
// #include <string>

// using namespace std;

// int main() {

//     // string은 엔터를 만나면 입력을 멈춘다.
//     string name;
//     string address("seoul");
//     string copyaddress(address);

//     char text[] = {'l', 'o', 'v', 'e', '\0'};

//     string title(text);

//     cout << address << "\n";
//     cout << copyaddress << "\n";
//     cout << text << "\n";
//     cout << title << "\n";

//     cout << name.size() << "\n";

//     return 0;
// }

// 문자열 길이

// #include <iostream>
// #include <string>
// using namespace std;

// int main() {

//     string str1 = "abcd";
//     string str2 = "efg";

//     str1 = str1 + str2;

//     if (str1 == "abcdefg") {
//         cout << "str1 is correct" << "\n";
//     } else {
//         cout << "str1 is Not correct" << "\n";
//     }

//     return 0;
// }

// string의 find -> 문자열 검색

// #include <iostream>
// #include <string>

// using namespace std;

// int main() {

//     string text = "Napster's pay-to-play service is officially out, "
//                   "and we have a review of the now-legit Napster. "
//                   "We also size up its companion music player from Samsung.";

//     cout << "offset of official = " << text.find("official") << "\n";
// }

// vector 클래스 사용

// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {

//     vector<int> v;

//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);

//     for (int i = 0; i < v.size(); i++) {

//         cout << v[i] << " ";
//         cout << endl;
//     }

//     v[0] = 10;
//     v[1] = 20;
//     v[2] = 30;
//     v.at(2) = 40;
//     for (int i = 0; i < v.size(); i++) {
//         cout << v[i] << " ";
//         cout << endl;
//     }

//     return 0;
// }

// class 사례

// class Circle {
// public:
//     int radius;       // 멤버 변수
//     double getArea(); // 멤버 함수
// }

// double
// Circle ::getArea() {
//     return 3.14 * radius * radius;
// }

// #include <iostream>

// using namespace std;

// class Circle {

// public:
//     int radius;
//     double getArea();
// };

// double Circle ::getArea() {
//     return 3.14 * radius * radius;
// }

// int main() {

//     Circle donut;

//     donut.radius = 3;
//     double area = donut.getArea();

//     cout << "donut : " << area << endl;

//     Circle pizza;
//     pizza.radius = 10;
//     double pizza_area = pizza.getArea();

//     cout << "pizza : " << pizza_area << endl;
// }

// 실습 4주차
// 1
// #include <iostream>
// #include <string>

// using namespace std;

// int main() {

//     string names[5];

//     cout << "input name : " << endl;

//     for (int i = 0; i < 5; i++) {

//         cout << "name :";
//         getline(cin, names[i]);
//     }

//     string last_name = names[0];

//     for (int i = 1; i < 5; i++) {

//         if (last_name < names[i]) {
//             last_name = names[i];
//         }
//     }

//     cout << "last name " << last_name << endl;
// }

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// int main() {

//     vector<string> names;
//     string input;

//     cout << "name" << endl;

//     for (int i = 0; i < 5; i++) {

//         cout << (i + 1) << ">>";
//         getline(cin, input);

//         names.push_back(input);
//     }

//     string last_name = names[0];

//     for (int i = 1; i < 5; i++) {

//         if (last_name < names[i]) {
//             last_name = names[i];
//         }
//     }

//     cout << "last name : " << last_name;
// }

// 3
// #include <iostream>
// using namespace std;

// class Rectangle {
// public:
//     int width;
//     int height;
//     int getArea() {
//         return width * height;
//     }
// };

// int main() {

//     Rectangle rect;

//     rect.width = 3;
//     rect.height = 5;

//     cout << "area : " << rect.getArea();
// }

// 4

// #include <iostream>
// #include <string>

// using namespace std;

// int main() {

//     string s, line;

//     cout << "write text line last string is '&' " << endl;

//     while (true) {

//         getline(cin, line);

//         if (line.find('&') != string::npos) {
//             line.erase(line.find('&'));
//             s += line;
//             break;
//         }

//         s += line + '\n';
//     }

//     cout << "finder : ";
//     string finder;
//     getline(cin, finder);

//     cout << "changer : ";
//     string changer;
//     getline(cin, changer);

//     size_t pos = 0;

//     while ((pos = s.find(finder, pos)) != string::npos) {
//         s.replace(pos, finder.length(), changer);
//         pos += changer.length();
//     }

//     cout << "result : " << s << endl;

//     return 0;
// }

// 생성자와 소멸자 순서

/*
바람직한 cpp 프로그램 작성법
클래스를 헤더파일과 cpp 파일을 분리하여 작성
클래스마다 분리 저장

클래스 선언 부 : 헤더파일에 저장
클래스 구현 부 : cpp파일에 저장

main() 등 전역 함수나 변수는 다른 cpp 파일에 분산 저장

접근 지정자
private
protected
public

*/

// #include <iostream>
// #include <string>
// using namespace std;

// class Circle {
// private:
//     int radius;

// public:
//     Circle();
//     Circle(int r);

//     double getarea();

//     int getradius();
//     bool setradius(int r);
// };

// int Circle::getradius() {

//     return radius;
// }

// bool Circle::setradius(int r) {
//     if (r > 30)
//         return false;
//     radius = r;
//     return true;
// }

// int main() {
//     Circle waffle(5);
//     waffle.setradius(5);

//     int radius;
//     radius = waffle.getradius();
// }

// 제네릭 프로그래밍 템플릿

// #include <iostream>
// using namespace std;

// template <class T>

// void print(T array[], int n) {

//     for (int i = 0; i < n; i++) {

//         cout << array[i] << '\t';

//         cout << endl;
//     }
// }

// void print(char array[], int n) {
//     for (int i = 0; i < n; i++) {

//         cout << (int)array[i] << '\t';
//     }
// }

// int main() {

//     int x[] = {1, 2, 3, 4, 5};
//     double d[] = {1.1, 2.2, 3.3, 4.4, 5.5};

//     print(x, 5);
//     print(d, 5);

//     char c[5] = {1, 2, 3, 4, 5};
//     print(c, 5);
// }

// 디폴트 인자를 이용한 함수

// #include <iostream>

// using namespace std;

// void f(char c = ' ', int line = 1);

// void f(char c, int line) {
//     for (int i = 0; i < line; i++) {
//         for (int i = 0; i < 10; i++) {
//             cout << c;
//         }

//         cout << '\n';
//     }
// }

// int main() {

//     f();

//     f('%');

//     f('@', 5);
// }

// 제네릭 함수 템플릿 이용

// #include <iostream>
// using namespace std;

// template <class T>
// T add(T arr[], int size) {

//     T sum = 0;

//     for (int i = 0; i < size; i++) {
//         sum += arr[i];
//     }

//     return sum;
// }

// int main() {
//     int x[] = {1, 2, 3, 4, 5};

//     double b[] = {1.1, 2.2, 3.3, 4.4, 5.5};

//     cout << "x sum" << add(x, 5) << endl;

//     cout << "b sum" << add(b, 5) << endl;
// }

// #include <iostream>

// using namespace std;

// template <class T>
// void reversearray(T *arr, int size) {
//     for (int i = 0; i < size / 2; i++) {

//         T temp = arr[i];
//         arr[i] = arr[size - 1 - i];
//         arr[size - 1 - i] = temp;
//     }
// }

// int main() {

//     int x[] = {1, 10, 100, 5, 4};
//     reversearray(x, 5);
//     for (int i = 0; i < 5; i++) {
//         cout << x[i] << ' ';

//         cout << endl;
//     }
// }

// 스트림 입출력 방식
//     입력된 키는 버퍼에 저장
//         엔터가 입력되면 버퍼에서 읽어가는 방식

// #include <iostream>

// using namespace std;

// #include <string>

// int main() {

//     string song("Falling in love with you");
//     string elvis("elvis presley");
//     string singer;

//     cout << song + "singer??";
//     cout << "(first string)" << elvis[0];
//     getline(cin, singer);
//     if (singer == elvis) {
//         cout << "correct";
//     } else {

//         cout << "incorrect " + elvis << endl;
//     }
// }
// getline 함수 사용법 cin.getline(string, 20);
// getline(cin, string);

// #include <iostream>
// using namespace std;

// int main() {
//     int arr[6] = {1, 2, 3, 4, 5, 6};

//     // 1) 포인터 변수 chr_ptr 선언
//     int *chr_ptr;

//     // 2) chr_ptr을 arr 배열의 시작 주소로 초기화
//     chr_ptr = arr;

//     chr_ptr++; // 포인터 증가 → arr[1]을 가리키게 됨

//     // 3) chr_ptr 출력
//     cout << chr_ptr << "\n"; // 출력: arr[1]의 주소 (예: 0x7ffee3b1d2b4)

//     // 4) *chr_ptr 출력 → arr[1]의 값
//     cout << *chr_ptr << "\n"; // 출력: 2

//     // 5) arr 출력 → 배열의 시작 주소
//     cout << arr << "\n"; // 출력: arr[0]의 주소 (예: 0x7ffee3b1d2b0)

//     // 6) arr+4 출력 → arr[4]의 주소
//     cout << arr + 4 << "\n"; // 출력: arr[4]의 주소 (예: 0x7ffee3b1d2c0)

//     // 7) &arr[3] 출력 → arr[3]의 주소
//     cout << &arr[3] << "\n"; // 출력: arr[3]의 주소 (예: 0x7ffee3b1d2bc)

//     // arr[4] 출력
//     cout << arr[4] << "\n"; // 출력: 5

//     // 8) chr_ptr을 이용하여 arr[3]의 값 출력
//     cout << *(chr_ptr + 2) << endl; // chr_ptr = arr+1 이므로, arr[3] = *(arr+1+2)

//     return 0;
// }

// #include <iostream>
// using namespace std;
// #include <string>

// int main() {

//     int arr[2][3] = {{11, 12, 13}, {21, 22, 23}};
//     int (*parr)[3]; // 배열포인터
//     int *p;
//     int **pt;
//     parr = arr;
//     cout << parr << arr;                                         // 주소 ptr == M
//     cout << parr + 1 << arr + 1;                                 // 주소 3 X 4byte 만큼 늘어남 parr+1 == arr+1
//     cout << *(parr + 1) << parr[1] << *(arr + 1) << arr[1];      // 주소
//     cout << **(parr + 1) << **(arr + 1) << *arr[1] << arr[1][0]; // 원소 값 : 21
//     p = arr[0];
//     cout << p << arr[0] << *arr;                      // p == arr[0] == *arr 각 원소의 시작주소
//     cout << *(p + 1) << *(arr[0] + 1) << *(*arr + 1); // 원소 값 : 12
//     pt = &p;                                          // pt = arr; (X)
//     cout << *pt << p;                                 // *pt == p
//     cout << **pt << *p;                               // **pt == *p
// }