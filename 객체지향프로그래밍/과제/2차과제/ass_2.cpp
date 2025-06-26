/*

과제2차 과제 공지 2025-06-14 00:00:00 ~ 2025-06-25 23:59:00
C++의 vector와 유사한 클래스를 구현

클래스명은 Vector(첫글자 대문자)으로 하고, C++의 vector와 유사한 클래스를 구현하라.
Vector 클래스의 구현 사항은 다음과 같다.

1. 템플릿을 적용하여 다양한 데이터 타입을 지원

2. 다음과 같은 생성자를 지원
    Vector(int capacity=1): capacity 만큼의 크기를 갖는 메모리를 동적 할당
    Vector(const Vector<T> &v): Vector v를 깊은 복사하는 복사 생성자
    Vector(const T* start, const T* end): start 포인터 위치에서 end 포인터 위치까지 배열의 값을 복사하는 생성자
       예시)
        int arr[] = { 1, 2, 3, 4, 5 };
        Vector<int> v(arr + 1, arr + 3); // Vector v에는 2, 3 요소가 복사됨

3. 다음과 같은 public 멤버 함수를 제공
   void pushBack(const T &value); // Vector의 마지막에 value를 추가
   void popBack(); // Vector의 마지막 요소를 제거
   T& at(int index); // index에 해당하는 요소를 리턴
   T& operator[](int index); // 배열의 인덱스 연산자와 동일한 기능, 쓰기 가능, 예) v[0] = value;
   const T& operator[](int index) const; // operator[]의 const 버전(읽기), 예) cout << v[0] << endl;
   Vector<T>& operator=(const Vector<T> &v); // Vector v의 값을 할당하는 연산자, 자기 자신을 리턴
   Vector<T> operator+(const Vector<T> &v); // 현재 벡터(this)의 뒤에 Vector v를 요소를 추가하여 새로운 Vector 객체를 리턴, 현재벡터의 값은 변경되면 안됨
   int size() const: 벡터에 저장된 요소의 수를 리턴

4. 동적 할당을하므로 소멸자에서 정리하는 코드 필요
5. 현재 할당된 메모리가 부족할 경우, 자동으로 할당된 메모리를 늘려주어야 함
6. at 멤버함수와 operator[]의 경우 인덱스의 범위가 유효하지 않을 경우 "out of range"라는 예외를 던짐

위의 요구사항을 만족하는 Vector를 구현하고,
main 함수에서 각 기능을 테스트하는 코드를 작성할 것

보고서 형식(다음과 같이 구성되어야 함)

1. 표지 - 제목, 학번, 이름으로 구성

2. 내용 구성

    - 파일 별 전체 코드

    - 실행 결과(스크린샷하여 문서 내에 첨부, main 함수의 테스트 결과)

   - 주요 코드 및 설명

제출 방법: 한글 또는 워드프로세서 등 문서 편집기를 이용하여 작성하되 PDF 파일로 변환하여 제출



*/

#include <iostream>
#include <stdexcept>
#include <string> // std::string을 사용하기 위해 추가

using namespace std;

template <class T>

class Vector {

private:
    T *data;
    int vector_size;
    int vector_capacity;

protected:
    void reserve(int reserve_capacity) {
        if (reserve_capacity <= vector_capacity) {
            return;
        }

        T *newData = new T[reserve_capacity];

        for (int i = 0; i < vector_size; i++) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        vector_capacity = reserve_capacity;
    }

public:
    // 생성자
    Vector(int capacity = 1)
        : data(new T[capacity]), vector_size(0), vector_capacity(capacity) {
    }

    // 깊은 복사 - 벡터 깊은 복사
    Vector(const Vector<T> &v)
        : data(new T[v.vector_capacity]), vector_size(v.vector_size), vector_capacity(v.vector_capacity) {

        for (int i = 0; i < vector_size; i++) {

            data[i] = v.data[i];
        }
    }

    // start 에서 end까지 배열 값 복사
    Vector(const T *start, const T *end) {
        int range_size = end - start;
        if (range_size < 0) {
            // 예외 처리
            throw std::out_of_range("error : 벡터 사이즈가 0보다 작아요");
        }

        vector_size = range_size;
        vector_capacity = range_size;
        data = new T[vector_capacity];

        for (int i = 0; i < vector_size; ++i) {
            data[i] = *(start + i);
        }
    }

    // 소멸자

    ~Vector() {
        delete[] data;
    }

    void push_back(const T &value) {

        if (vector_size >= vector_capacity) {
            reserve(vector_capacity * 2);
        }

        data[vector_size] = value;
        vector_size++;
    }

    void pop_back() {

        if (vector_size == 0) {

            throw std::out_of_range("error : popback 에러");
        }
        --vector_size;
    }

    T &at(int index) {

        if (index < 0 || index >= vector_size) {

            throw std::out_of_range(" error : 범위를 벗어남");
        }

        return data[index];
    }

    const T &operator[](int index) const {
        if (index < 0 || index >= vector_size) {
            throw std::out_of_range("예외처리 : 범위를 벗어남");
        }

        return data[index];
    }

    T &operator[](int index) {
        if (index < 0 || index >= vector_size) {
            throw std::out_of_range("예외처리 : 범위를 벗어남");
        }

        return data[index];
    }

    Vector<T> &operator=(const Vector<T> &v) {
        if (this != &v) {
            delete[] data;

            vector_capacity = v.vector_capacity;
            vector_size = v.vector_size;

            data = new T[vector_capacity];

            for (int i = 0; i < vector_size; ++i) {
                data[i] = v.data[i];
            }
        }
        return *this;
    }

    Vector<T> operator+(const Vector<T> &v) const {
        Vector<T> result(vector_size + v.vector_size);

        for (int i = 0; i < vector_size; i++) {
            result.push_back(data[i]);
        }

        for (int i = 0; i < v.vector_size; ++i) {
            result.push_back(v.data[i]);
        }

        return result;
    }

    int size() const {
        return vector_size;
    }
};

// 벡터의 내용을 출력하는 헬퍼 함수
template <typename T>
void printVector(const string &name, const Vector<T> &v) {
    cout << name << " (size: " << v.size() << "): ";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main() {
    cout << "push_back 테스팅" << endl;
    Vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    printVector("v1", v1);
    cout << endl;

    cout << "복사 생성자 테스팅" << endl;
    Vector<int> v2(v1);
    printVector("v2 -> v1의 복사본", v2);
    cout << "v2에 40 추가" << endl;
    v2.push_back(40);
    printVector("v1 (v2 변경 후)", v1);
    printVector("v2 (40 추가 후)", v2);
    cout << endl;

    cout << "범위 생성자 테스트" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    Vector<int> v3(arr + 1, arr + 4);
    printVector("v3 -> 배열의 일부로 생성", v3);
    cout << endl;

    cout << "대입 연산자(=) 테스트" << endl;
    Vector<int> v4;
    v4 = v3;
    printVector("v4 ->v3 대입 후", v4);
    cout << "자기 자신에게 대입" << endl;
    v4 = v4;
    printVector("v4 -> 자기 자신에게 대입 후", v4);
    cout << endl;

    cout << " + 연산자 테스트" << endl;
    Vector<int> v5 = v1 + v3;
    printVector("v5 (v1 + v3)", v5);
    cout << endl;

    cout << "pop_back 테스트" << endl;
    printVector("v5 : pop_back 전", v5);
    v5.pop_back();
    printVector("v5 : pop_back 후", v5);
    cout << endl;

    cout << "인덱스 연산자 테스트" << endl;
    cout << "v5[0] = " << v5[0] << endl;
    cout << "v5[0]에 100 할당" << endl;
    v5[0] = 100;
    printVector("v5 (v5[0] 수정 후)", v5);
    cout << endl;

    cout << "at() 멤버 함수 테스팅" << endl;
    cout << "v5.at(1) = " << v5.at(1) << endl;
    cout << endl;

    cout << "operator[] 테스트" << endl;
    const Vector<int> v_const(arr, arr + 5);
    printVector("v_const", v_const);
    cout << "v_const[2] = " << v_const[2] << endl;

    cout << endl;

    cout << "템플릿-string 자료형 테스트 " << endl;
    Vector<string> v_str;
    v_str.push_back("Hello");
    v_str.push_back("C++");
    v_str.push_back("Vector");
    printVector("v_str", v_str);
    cout << endl;

    cout << "예외 처리 테스트" << endl;
    try {
        cout << "v5.at(100)" << endl;
        v5.at(100);
    } catch (const out_of_range &e) {
        cerr << "예외 발생: " << e.what() << endl;
    }

    try {
        cout << "빈 벡터에 pop_back 넣었을때" << endl;
        Vector<int> empty_vec;
        empty_vec.pop_back();
    } catch (const out_of_range &e) {
        cerr << "예외 발생: " << e.what() << endl;
    }
    cout << endl;

    return 0;
}