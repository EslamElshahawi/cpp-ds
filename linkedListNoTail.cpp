#include <iosream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data) : data(data) { }
};

class LinkedList {
private:
    Node* head;

public:
    void print(){
        for(Node* cur = head; cur; cur = cur->next)
            cout << cur->data << "\t";
        cout << "\n";
    }

    void add_element(int value){
        Node* item = new Node(value);
        item->next = head;
        head = item;
    } // reversed list O(1)

    Node* get_tail(){
        if(!head)
            return nullptr;
        Node* tail = head;
        while(tail){
            tail = tail->next;
        }
        return tail;
    }
}


int main(){

}