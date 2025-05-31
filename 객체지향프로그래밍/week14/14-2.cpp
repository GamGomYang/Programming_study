#include <iostream>

using namespace std;

class Calculator {

protected:
    int value1, value2;

public:
    friend istream &operator>>(istream &, Calculator &);
    virtual int calculate() const = 0;
};

istream &operator>>(istream &in, Calculator &calc) {
    return in >> calc.value1 >> calc.value2;
}

class Adder {
};

class Substractor {
};

void calculate(Calculator &calc) {
    cout << "두개의 수를 입력하세요" << endl;

    cin >> calc;

    cout << "결과" << calc.calculate() << endl;
}

int main() {

    Adder adder;
    Substractor substractor;

    calculate(adder);
    calculate(substractor);
}