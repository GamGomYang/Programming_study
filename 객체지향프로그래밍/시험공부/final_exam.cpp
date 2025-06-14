// #include <iostream>

// using namespace std;

// class Circle {

//     int radius;

// public:
//     Circle() {
//         radius = 1;
//     }

//     Circle(int r) {

//         radius = r;
//     }

//     void setRadius(int r) {

//         radius = r;
//     }

//     double getArea();
// };

// double Circle ::getArea() {

//     return 3.14 * radius * radius;
// }

// int main() {

//     Circle circleArray[3];

//     circleArray[0].setRadius(10);

//     circleArray[1].setRadius(20);

//     circleArray[2].setRadius(30);

//     for (int i = 0; i < 3; i++) {
//         객체 배열로 멤버 접근

//                 cout
//             << "circle" << i << "area" << circleArray[i].getArea() << endl;
//     }

//     Circle *p;
//     p = circleArray;
//     for (int i = 0; i < 3; i++) {
//         객체 포인터로 배열 접근
//                 cout
//             << "circle" << i << "area" << p->getArea() << endl;
//         p++;
//     }
// }

// #include <iostream>

// using namespace std;

// class Circle {

//     int radius;

// public:
//     Circle() {
//         radius = 1;
//     }

//     double getArea();
// };

// double Circle::getArea() {
//     return 3.14 * radius * radius;
// }

// int main() {

//     Circle circleArray[3] = {Circle(), Circle(), Circle()};

//     for (int i = 0; i < 3; i++) {

//         cout << circleArray[i].getArea() << endl;
//     }
// }

// new 와 delete를 이용한 동적할당

// #include <iostream>

// using namespace std;

// int main() {

//     int *p;

//     p = new int;

//     if (!p) {

//         cout << "error";
//         return 0;
//     }

//     *p = 5;

//     cout << *p << endl;

//     int n = *p;

//     cout << n << endl;

//     delete p;

//     // p 메모리 반환
// }
