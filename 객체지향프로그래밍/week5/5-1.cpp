#include <iostream>
#include <string>
using namespace std;
int main() {
    string name;
    string address("seoul");
    char text[] = {'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0'};
    string copyAddress(address);
    string title(text);
    cin >> name;
    cout << address << "\n";
    cout << copyAddress << "\n";
    cout << text << "\n";
    cout << title << "\n";
    return 0;
}