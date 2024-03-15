#include <iostream>
#include <cassert>

using namespace std;

class Queue{
    int size;
	int front = 0;
	int rear = 0;
	int added_elements;
	int *array;

public:
    Queue(int size) : size(size) {
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

		for (int cur = front, step = 0; step < added_elements; ++step, cur = next(cur))
			cout << array[cur] << " ";
		cout << "\n\n";
	}

	int isEmpty() {
		return added_elements == 0;
	}

	bool isFull() {
		return added_elements == size;
	}

	int front_val(){
		return front;
	}
};

class Stack{
	Queue q;
	int added_elements;

	void insert_at_front(int x){
		int size = added_elements;
		q.enqueue(x);
		while(size--)
			q.enqueue(q.dequeue);

		++added_elements;
	}

public:
	Stack(int size) : q(size) {

	}

	void push(int x){
		insert_at_front(x);
	}

	int pop(){
		return q.dequeue();
	}

	int peek(){
		return q.front_val();
	}

	int isFull(){
		return q.isFull();
	}
};

int main(){

}
    