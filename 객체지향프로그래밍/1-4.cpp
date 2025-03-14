#include <iostream>
using namespace std;

int main() {
    char c[100];
    int count = 0;
    cout << "문자들을 입력하세요." << endl;
    cin.getline(c, 100);

        for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] == 'x' || c[i] == 'X') {
            count++;
        }
    }
    cout << "X의 개수는 " << count << endl;
    return 0;
}
