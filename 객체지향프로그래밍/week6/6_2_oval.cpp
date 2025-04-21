#include "oval.h"
#include <iostream>
using namespace std;

Oval::Oval() {
    width = 1;
    height = 1;
}

Oval::Oval(int w, int h) {
    width = w;
    height = h;
}

Oval::~Oval() {
    cout << "Oval 소멸 : width = " << width << ", height = " << height << endl;
}

int Oval::getWidth() {
    return width;
}

int Oval::getHeight() {
    return height;
}

void Oval::set(int w, int h) {
    width = w;
    height = h;
}

void Oval::show() {
    cout << "width = " << width << ", height = " << height << endl;
}
