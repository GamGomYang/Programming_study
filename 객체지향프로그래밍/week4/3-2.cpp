//(1)
// #include <iostream>
// using namespace std;

// int big(int a, int b) {
//     int max = (a > b) ? a : b;
//     return max;
// }

// int big(int a, int b, int max_size) {
//     int max = (a > b) ? a : b;
//     return max;
// }

// int main() {
//     int x = big(3, 5);
//     int y = big(300, 60);
//     int z = big(30, 60, 50);
//     cout << x << ' ' << y << ' ' << z << endl;
// }

//(2)
#include <iostream>
using namespace std;

int big(int a, int b, int max_size = 100) {
    int max = (a > b) ? a : b;
    return max;
}

int main() {
    int x = big(3, 5);
    int y = big(300, 60);
    int z = big(30, 60, 50);
    cout << x << ' ' << y << ' ' << z << endl;
}
