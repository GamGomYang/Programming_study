#include <iostream>

using namespace std;

class Color {
    int red;
    int green;
    int blue;

public:
    Color(int r, int g, int b) : red(r), green(g), blue(b) {}

    void show() const {
        cout << red << " " << green << " " << blue << endl;
    }

    void setColor(int r, int g, int b) {
        red = r;
        green = g;
        blue = b;
    }
};

int main() {
    Color screenColor(255, 0, 0);
    Color *p;
    p = &screenColor;
    p->show();

    Color colors[3];
    p = colors;
    p->setColor(255, 0, 0);
    (p + 1)->setColor(0, 255, 0);
    (p + 2)->setColor(0, 0, 255);

    for (int i = 0; i < 3; i++) {
        (p + i)->show();
    }

    return 0;
}