#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class Vector {
private:
    // Vector 클래스의 private 멤버 변수들
    T *data;         // 동적 할당된 배열 포인터 - 실제 데이터를 저장하는 메모리
    int currentSize; // 실제 저장된 요소 개수 - 현재 벡터에 들어있는 원소의 수
    int maxCapacity; // 할당된 메모리 용량 - 현재 할당된 메모리 크기 (>= currentSize)

    // 요구사항 5: 현재 할당된 메모리가 부족할 경우, 자동으로 할당된 메모리를 늘려주는 내부 함수
    // newCapacity 크기로 메모리를 재할당하고 기존 데이터를 복사
    void reserve(int newCapacity) {
        // 이미 충분한 용량이 있으면 아무것도 하지 않음
        if (newCapacity <= maxCapacity)
            return;

        // 새로운 용량으로 메모리 재할당
        T *newData = new T[newCapacity];

        // 기존 데이터를 새 메모리로 복사

        for (int i = 0; i < currentSize; ++i) {
            newData[i] = data[i];
        }

        // 기존 메모리 해제
        delete[] data;

        // 새로운 메모리와 용량으로 업데이트
        data = newData;
        maxCapacity = newCapacity;
    }

public:
    // 요구사항 2-1: Vector(int capacity=1) 생성자 - capacity 만큼의 크기를 갖는 메모리를 동적 할당
    // 기본값 1로 설정하여 capacity를 지정하지 않으면 1개 요소를 저장할 수 있는 메모리 할당
    Vector(int capacity = 1)
        : data(new T[capacity]), currentSize(0), maxCapacity(capacity) {
        // 멤버 초기화 리스트를 사용하여 초기화
        // data: capacity 크기의 T 타입 배열을 동적 할당
        // currentSize: 초기에는 요소가 없으므로 0
        // maxCapacity: 할당된 메모리 크기는 capacity
    }

    // 요구사항 2-2: 복사 생성자 (깊은 복사) - Vector v를 깊은 복사
    // 다른 Vector 객체의 모든 데이터를 복사하여 새로운 Vector 객체 생성
    Vector(const Vector<T> &v)
        : data(new T[v.maxCapacity]), currentSize(v.currentSize), maxCapacity(v.maxCapacity) {
        // 멤버 초기화 리스트로 v와 동일한 용량의 메모리 할당
        // currentSize와 maxCapacity도 v와 동일하게 설정

        // 깊은 복사: v의 모든 데이터를 새로 할당된 메모리에 복사
        for (int i = 0; i < currentSize; ++i) {
            data[i] = v.data[i];
        }
    }

    // 요구사항 2-3: 범위 생성자 - start 포인터 위치에서 end 포인터 위치까지 배열의 값을 복사
    // 예시: int arr[] = {1, 2, 3, 4, 5}; Vector<int> v(arr + 1, arr + 3); // 2, 3, 4 요소가 복사됨
    Vector(const T *start, const T *end)
        : currentSize(static_cast<int>(end - start)), maxCapacity(currentSize), data(nullptr) {
        // end - start로 범위의 크기를 계산하여 currentSize 설정
        // maxCapacity는 currentSize와 동일하게 설정 (정확히 필요한 만큼만 할당)
        // data는 일단 nullptr로 초기화

        // 유효하지 않은 범위 체크 (end가 start보다 앞에 있으면 음수)
        if (currentSize < 0)
            throw std::out_of_range("예외처리 : Invalid range");

        // 필요한 크기만큼 메모리 할당
        data = new T[maxCapacity];

        // start부터 end까지의 모든 요소를 복사
        for (int i = 0; i < currentSize; ++i) {
            data[i] = *(start + i);
        }
    }

    // 요구사항 4: 소멸자 - 동적 할당된 메모리를 정리
    // Vector 객체가 소멸될 때 자동으로 호출되어 메모리 누수 방지
    ~Vector() {
        delete[] data; // 동적 할당된 배열 메모리 해제
    }

    // 요구사항 3-1: pushBack - Vector의 마지막에 value를 추가
    // 벡터의 끝에 새로운 요소를 추가하는 함수
    void pushBack(const T &value) {
        // 현재 용량이 부족하면 자동으로 용량을 늘림 (요구사항 5)
        if (currentSize >= maxCapacity) {
            reserve(maxCapacity * 2); // 용량을 2배로 늘림
        }

        // 마지막 위치에 새 요소 추가하고 크기 증가
        data[currentSize++] = value;
    }

    // 요구사항 3-2: popBack - Vector의 마지막 요소를 제거
    // 벡터의 마지막 요소를 제거하는 함수
    void popBack() {
        // 빈 벡터에서 popBack을 시도하면 예외 발생
        if (currentSize == 0)
            throw std::out_of_range("예외처리 : popback 에러");

        // 크기만 감소시켜 마지막 요소를 "제거" (실제로는 메모리에서 삭제하지 않음)
        --currentSize;
    }

    // 요구사항 3-3: at - index에 해당하는 요소를 리턴 (범위 검사 포함)
    // 요구사항 6: 인덱스의 범위가 유효하지 않을 경우 "out of range" 예외를 던짐
    T &at(int index) {
        // 인덱스가 유효한 범위인지 검사
        if (index < 0 || index >= currentSize)
            throw std::out_of_range("예외처리 : out of range");

        // 유효한 인덱스면 해당 요소의 참조 반환
        return data[index];
    }

    // 요구사항 3-4: operator[] (비-const 버전) - 배열의 인덱스 연산자와 동일한 기능, 쓰기 가능
    // 예시: v[0] = value; 형태로 사용 가능
    // 요구사항 6: 인덱스의 범위가 유효하지 않을 경우 "out of range" 예외를 던짐
    T &operator[](int index) {
        // 인덱스가 유효한 범위인지 검사
        if (index < 0 || index >= currentSize)
            throw std::out_of_range("예외처리 : out of range");

        // 유효한 인덱스면 해당 요소의 참조 반환 (쓰기 가능)
        return data[index];
    }

    // 요구사항 3-4: operator[] const 버전 - 읽기 전용 버전
    // 예시: cout << v[0] << endl; 형태로 사용 가능
    // 요구사항 6: 인덱스의 범위가 유효하지 않을 경우 "out of range" 예외를 던짐
    const T &operator[](int index) const {
        // 인덱스가 유효한 범위인지 검사
        if (index < 0 || index >= currentSize)
            throw std::out_of_range("예외처리 : out of range");

        // 유효한 인덱스면 해당 요소의 const 참조 반환 (읽기 전용)
        return data[index];
    }

    // 요구사항 3-5: 대입 연산자 - Vector v의 값을 할당하는 연산자, 자기 자신을 리턴
    // 깊은 복사를 통해 다른 Vector의 모든 데이터를 복사
    Vector<T> &operator=(const Vector<T> &v) {
        // 자기 자신에게 대입하는 경우는 아무것도 하지 않음 (자기 대입 방지)
        if (this != &v) {
            // 기존 메모리 해제
            delete[] data;

            // v와 동일한 용량과 크기로 설정
            maxCapacity = v.maxCapacity;
            currentSize = v.currentSize;

            // 새로운 메모리 할당
            data = new T[maxCapacity];

            // v의 모든 데이터를 깊은 복사
            for (int i = 0; i < currentSize; ++i) {
                data[i] = v.data[i];
            }
        }

        // 자기 자신의 참조를 반환 (연쇄 대입 지원)
        return *this;
    }

    // 요구사항 3-6: 벡터 연결 연산자 + - 현재 벡터(this)의 뒤에 Vector v를 요소를 추가하여 새로운 Vector 객체를 리턴
    // 현재벡터의 값은 변경되면 안됨 (const 멤버 함수로 구현)
    Vector<T> operator+(const Vector<T> &v) const {
        // 결과 벡터를 생성 (크기는 this의 크기 + v의 크기)
        Vector<T> result(currentSize + v.currentSize);

        // 현재 벡터(this)의 모든 요소를 결과 벡터에 복사
        for (int i = 0; i < currentSize; ++i) {
            result.pushBack(data[i]);
        }

        // v 벡터의 모든 요소를 결과 벡터에 추가
        for (int i = 0; i < v.currentSize; ++i) {
            result.pushBack(v.data[i]);
        }

        // 새로운 Vector 객체를 반환 (현재 벡터는 변경되지 않음)
        return result;
    }

    // 요구사항 3-7: size - 벡터에 저장된 요소의 수를 리턴
    // const 멤버 함수로 구현하여 벡터의 상태를 변경하지 않음
    int size() const {
        return currentSize; // 현재 저장된 요소의 개수 반환
    }
};

// main 함수: Vector 클래스의 모든 기능을 테스트하는 코드
int main() {
    try {
        Vector<int> v1;
        v1.pushBack(10);
        v1.pushBack(20);
        v1.pushBack(30);

        std::cout << "v1: ";
        for (int i = 0; i < v1.size(); ++i)
            std::cout << v1[i] << ' ';
        std::cout << "\n";

        Vector<int> v2(v1);
        v2.pushBack(40);

        std::cout << "v2 (copy of v1 + 40): ";
        for (int i = 0; i < v2.size(); ++i)
            std::cout << v2.at(i) << ' ';
        std::cout << "\n";

        int arr[] = {1, 2, 3, 4, 5};
        Vector<int> v3(arr + 1, arr + 4);

        std::cout << "v3 (range arr[1]..arr[3]): ";
        for (int i = 0; i < v3.size(); ++i)
            std::cout << v3[i] << ' ';
        std::cout << "\n";

        Vector<int> v4;
        v4 = v3;

        std::cout << "v4 (= v3): ";
        for (int i = 0; i < v4.size(); ++i)
            std::cout << v4[i] << ' ';
        std::cout << "\n";

        Vector<int> v5 = v1 + v3;

        std::cout << "v5 (v1 + v3): ";
        for (int i = 0; i < v5.size(); ++i)
            std::cout << v5[i] << ' ';
        std::cout << "\n";

        v5.popBack();

        std::cout << "v5 after popBack: ";
        for (int i = 0; i < v5.size(); ++i)
            std::cout << v5[i] << ' ';
        std::cout << "\n";

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}
