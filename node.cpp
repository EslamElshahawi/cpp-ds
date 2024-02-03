#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;



void insertNode(int value){
    Node* new_node, *last_node;
    new_node = new Node;
    new_node->data = value;

    if(head == NULL){
        head = new_node;
        new_node->next = NULL;
    } else{
        last_node = head;

        while(last_node->next != NULL){
            last_node = last_node->next;

        }
        last_node->next = new_node;
        new_node->next = NULL;
    }
}
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void print_recursive(Node* head){
    if(head != NULL){
        cout << head->data << " ";
        print_recursive(head->next); 
    }
    
    cout << endl;
}

void print_reversed(Node* head){
    if(head == NULL){
        return;
    }
    print_reversed(head->next);
    cout<< head->data << " ";
}

Node* find(int value){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int main(){
    insertNode(5);
    insertNode(10);
    insertNode(12);
    print(head);
    print_recursive(head);
    print_reversed(head);
    cout << find(5);
}