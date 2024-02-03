#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data) : data(data) {};
};

class LinkedList{
private:
    Node* head = NULL ;
    Node* tail = NULL ;
    int length = 0 ;
public:
    void insert_end(int value){
        Node* new_node = new Node(value);
        if(head == NULL){
            head = new_node;
            new_node->next = NULL;
            tail = new_node; 
        }else {
            tail->next = new_node;
            tail = new_node;
            new_node = NULL;
        }
    }

    void print(){
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data;
            temp = temp->next;
        }
    }
};

int main(){
    LinkedList l;
    l.insert_end(5);
    l.insert_end(6);
    l.insert_end(7);
    l.print();
}