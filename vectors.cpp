#include <iostream>

using namespace std;

class Vector{
private:
    int *arr = nullptr;
    int size = 0;
    int capacity;
    void expand_capacity(){
        capacity *= 2;
        cout << "Expand to" << capacity << endl;
        int *arr2 = new int[capacity];
        for(int i = 0; i < size+1; i++){
            arr2[i] = arr[i];
        }
        swap(arr2, arr);
        delete[] arr2;
    }

public:
    Vector(int size):
        size(size){
            if(size < 0)
                size = 1;
            capacity = size + 10;
            arr = new int[capacity];
    }
    ~Vector(){
        delete[] arr;
        arr = nullptr;
    }

    void set(int idx ,int val) {
        assert(idx < size && idx >= 0);
        arr[idx] = val;
    }

    int get(int idx){
        assert(idx < size && idx >= 0);
        return arr[idx];
    }

    int find(int value) {
        for(int i = 0; i < size; i++) {
            if (arr[i] == value)    
                return i;
        }
        return -1;
    }

    int find_transposition(int value){
        for(int i = 0; i < size; i++){
            if(arr[i] == value){
                if(i == 0)
                    return 0;
                swap(arr[i], arr[i - 1]);
                return i - 1;
            }
        }
        return -1;
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << endl;
        }
    }

    

    void push_back(int value){
        if (size == capacity)
            expand_capacity();
        arr[size++] = value;
    }

    void insert(int idx, int value){
        assert(idx < size && idx >= 0);

        if (capacity == size){
            expand_capacity();
        }
        for(int i = size-1; i >= idx; i--){
            arr[i+1] = arr[i];
        }
        arr[idx] = value;
        ++size;
    }

    void right_rotate(){
        int rotated_num = arr[size - 1];

        for(int i = size-2; i >= 0; i--)
            arr[i+1] = arr[i];

        arr[0] = rotated_num;

    }

    void right_rotate(int times){
        times %= size;

        while(times--)
            right_rotate();
    }

    void left_rotate(){
        int rotated_num = arr[0];

        for(int i = 0; i <= size; i++)
            arr[i] = arr[i + 1];

        arr[size - 1] = rotated_num;

    }

    int pop(int idx){
        assert(idx < size && idx >= 0);
        int element = arr[idx];
        for(int i = idx; i < size; i++){
            arr[i] = arr[i+1];
        }
        size--;
        return element;
    }


};

int main(){
    Vector v(4);
    for(int i = 0; i < 4; i++){
        v.set(i, i);
    }

    int idx2 = v.find(5);

    v.print();
    cout  << "the value 0 is in idx: " << idx2 << endl;
    cout << v.find_transposition(2) << endl;
    v.print();
}