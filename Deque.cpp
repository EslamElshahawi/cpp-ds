#include <iostream>
#include <cassert>

using namespace std;

class Deque{
    int front = 0;
    int rear = 0;
    int size;
    int added_elements;
    int *array;

public:
    Deque(int size) : size(size) {
        array = new int[size];
    }

    ~Deque(){
        delete[] array;
    }

    int next(int pos){
        return (pos + 1) % size;
    }

    int prev(int pos){
        return (pos - 1 + size) % size;
    }

    void enqueue_rear(int value) {
		assert(!isFull());
		array[rear] = value;
		rear = next(rear);
		added_elements++;
	}

    void enqueue_front(int value){
        assert(!isFull());
        front = prev(front);
        array[front] = value;
        added_elements++;
    }

    int dequeue_front() {
		assert(!isEmpty());
		int value = array[front];
		front = next(front);
		--added_elements;
		return value;
	}

    int dequeue_rear(){
        assert(!isEmpty());
        rear = prev(rear);
        int value = array[rear];
        --added_elements;
        return value;
    }

    int isEmpty() {
		return added_elements == 0;
	}

	bool isFull() {
		return added_elements == size;
	}
};