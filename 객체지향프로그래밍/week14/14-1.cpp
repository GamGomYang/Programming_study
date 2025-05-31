#include <iostream>

using namespace std;

int main() {
    Shape *p[3];

    p[0] = new Circle("빈대떡", 10);
    p[1] = new Circle("찰떡", 30, 40);
    p[2] = new Circle("토스트", 30, 40);

    for (int i = 0; i < 3; i++) {

        cout << p[i]->getName() << "넓이는" << p[i]->getArea() << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete p[i];
    }
}