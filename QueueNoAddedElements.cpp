#include <iostream>
#include <cassert>

using namespace std;

class Queue{
    int size;
	int front = 0;
	int rear = 0;
	int *array;

public:
    Queue(int size) : size(size + 1) {
        array = new int[size];
    }
    ~Queue(){
        delete[] array;
    }
    int next(int pos) {
		return (pos + 1) % size;	
	}

	void enqueue(int value) {
		assert(!isFull());
		array[rear] = value;
		rear = next(rear);
		added_elements++;
	}

	int dequeue() {
		assert(!isEmpty());
		int value = array[front];
		front = next(front);
		--added_elements;
		return value;
	}

	void display() {
		cout << "Front " << front << " - rear " << rear << "\t";
		if (isFull())
			cout << "full";
		else if (isEmpty()) {
			cout << "empty\n\n";
			return;
		}
		cout << "\n";

		for (int cur = front; cur != rear; cur = next(cur))
			cout << array[cur] << " ";
		cout << "\n\n";
	}

	int isEmpty() {
		return front == rear;
	}

	bool isFull() {
		return next(rear) == front;
	}

	int front_val(){
		return front;
	}
};