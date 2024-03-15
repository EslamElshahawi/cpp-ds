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

class PriorityQueue{
private:
    int size;
    int added_elements;
    Queue q1, q2, q3;

public:
    PriorityQueue(int size) : size(size), q1(size), q2(size), q3(size){}

    void enqueue(int value, int priority){
        assert(!isFull);

        if(priority == 3)
            q3.enqueue(value);
        else if(priority == 2)
            q2.enqueue(value);
        else if(priority == 1)
            q1.enqueue(value);
        else
            assert(false);
        ++added_elements;
    }

    int dequeue(){
        assert(!isEmpty);

        if(!q3.isEmpty)
            return q3.dequeue();
        else if(!q2.isEmpty)
            return q2.dequeue();
        else 
            return q1.dequeue();
    }

    void display(){
        if(!q3.isEmpty){
            cout << "Priority #3 Tasks: ";
            q3.display;
        }
        else if(!q2.isEmpty){
            cout << "Priority #2 Tasks: ";
            q2.display();
        }
        else if(!q1.isEmpty){
            cout << "Priority #1 Tasks: ";
            q1.display();
        }

    }

    bool isFull(){
        return added_elements == size;
    }

    bool isEmpty(){
        return added_elements == 0;
    }
};