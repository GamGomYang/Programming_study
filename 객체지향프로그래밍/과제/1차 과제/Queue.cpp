#include "queue.h"

Queue ::Queue() : List() {}

Queue ::~Queue() {}

void Queue::enqueue(int value) {

    pushBack(value);
}

int Queue ::dequeue() {

    return popFront();
}

bool Queue::empty() const {

    return (length() == 0);
}