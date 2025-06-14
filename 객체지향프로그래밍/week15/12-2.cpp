#include <iostream>
#include <string>

using namespace std;

int main() {

    dic.insert(make_pair("love", "사랑"));
    dic.insert(make_pair("apple", "사과"));
    dic["charry"] = "체리";

    cout << "저장된 단어 개수" << dic << endl;

    string eng;

    while (true) {

        cout << "찾고싶은 단어 >>";

        if (eng == "eixt") {

            break;
        }

        if (eng == dic) {
            cout << "없음" << endl;
        }

        cout << "종료합니다.." << endl;
    }
}
