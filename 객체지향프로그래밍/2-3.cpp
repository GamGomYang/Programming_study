#include <iostream>
using namespace std;

bool bigger(int a, int b, int &big) {
    if (a == b) {
        big = a;
        return true;
    } else {
        big = (a > b) ? a : b;
        return false;
    }
}

int main() {
    int x, y, big;
    bool b;

    cout << "두 정수를 입력하세요>> ";
    cin >> x >> y;

    b = bigger(x, y, big);
    if (b)
        cout << "same" << endl;
    else
        cout << "큰 수는 " << big << endl;

    return 0;
}
