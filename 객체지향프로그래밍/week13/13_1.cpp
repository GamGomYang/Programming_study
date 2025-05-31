#include <iostream>
using namespace std;

class Person {
    string name;
    int age;

public:
    Person(const string &name = "", int age = 1) : name(name), age(age) {}
    const string &getName() const { return name; }
};

int main() {
}