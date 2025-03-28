#include <iostream>
using namespace std;

double Maxnum(double arr[], int size) {
    double maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    double a[5];
    cout << "5개의 실수를 입력하라 >> ";
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    cout << "제일 큰 수 = " << Maxnum(a, 5) << endl;
    return 0;
}
