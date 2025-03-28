#include <iostream>
using namespace std;

char &find(char a[], char c, bool &success) {
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] == c) {
            success = true;
            return a[i];
        }
    }

    success = false;

    static char dummy = '\0';
    return dummy;
}

int main() {
    char s[] = "Mike";
    bool b = false;
    char &loc = find(s, 'M', b);
    if (!b) {
        cout << "M을 발견할 수 없다" << endl;
        return 0;
    }
    loc = 'm';
    cout << s << endl;

    return 0;
}
