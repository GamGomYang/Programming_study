#include "Queue.h"
#include <iostream>
using namespace std;

int main() {
    Queue queue;
    int input;
    int size;

    cout << "큐에 입력할 사이즈를 입력해주세요 : ";

    cin >> size;

    cout << endl;

    int queue_status[size];

    for (int i = 1; i < size + 1; i++) {

        cout << i << "번째 큐 입력 값 : ";

        cin >> input;

        queue.enqueue(input);
        queue_status[i - 1] = input;
    }
    cout << endl;

    cout << "현재 queue의 상황" << endl;
    cout << endl;

    cout << "   <-- dequeue " << "| ";

    for (int k = 0; k < size; k++) {
        cout << " " << queue_status[k] << " |";
    }
    cout << " <-- enqueue    ";
    cout << endl;
    cout << endl;

    cout << "몇 번째 까지 출력 하실 건가요? : ";
    cin >> size;
    int count = 0;

    for (int i = 0; i < size; i++) {
        cout << (i + 1) << "번째 dequeue : ";

        cout << queue.dequeue() << " " << endl;
        count++;
    }

    cout << endl;

    cout << "나머지 큐 전체 출력" << endl;
    count++;

    while (!queue.empty()) {
        cout << count << "번째 dequeue" << queue.dequeue() << " " << endl;

        count++;
    }

    return 0;
}
