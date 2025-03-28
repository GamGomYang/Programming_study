#include <iostream>
using namespace std;

int sum(int a, int b) {
    int res = 0;
    for (int k = a; k <= b; k++) {
        res += k;
    }
    return res;
}

int main() {
    int n;
    cout << "끝수를 입력하세요>>";
    cin >> n;
    if (n <= 0) {
        cout << "양수를 입력하세요!" << endl;
        return 0;
    }
    cout << "1에서 " << n << "까지의 합은 " << sum(1, n) << "입니다." << endl;
    return 0;
}
