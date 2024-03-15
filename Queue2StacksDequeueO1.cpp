#include <iostream>
#include <cassert>
using namespace std;

class Stack {
private:
	int size { };
	int top { };
	int* array { };
public:
	Stack(int size) :
			size(size), top(-1) {
		array = new int[size];
	}

	~Stack() {
		delete[] array;
	}

	void push(int x) {
		assert(!isFull());
		array[++top] = x;
	}

	int pop() {
		assert(!isEmpty());
		return array[top--];
	}

	int peek() {
		assert(!isEmpty());
		return array[top];
	}

	int isFull() {
		return top == size - 1;
	}

	int isEmpty() {
		return top == -1;
	}

	void display() {
		for (int i = top; i >= 0; i--)
			cout << array[i] << " ";
		cout << "\n";
	}
};

class Queue{
private:
    Stack s1, s2;
    int added_elements;
    int size;

    void move(Stack &from, Stack &to){
        while(!from.isEmpty()){
            to.push(from.pop);
        }
    }
public:
    Queue(int size) : size(size), s1(size), s2(size) {}
    
    void enqueue(int value){
        assert(!isFull);
        move(s1, s2);
        s1.push(value);
        move(s2, s1);
        added_elements++;
    }

    int dequeue(){
        assert(!isEmpty);
        int value = s1.pop();
        added_elements--;
        return value;
    }

    bool isFull(){
        return size == added_elements;
    }

    bool isEmpty(){
        return added_elements == 0;
    }
};

int main(){
    
}