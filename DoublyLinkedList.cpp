#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data){}

    void set(Node* next, Node* prev){
        this->next = next;
        this->prev = prev;
    }
};

class LinkedList{
private:
    Node* head;
    Node* tail;
    int length = 0;

    vector<Node*> debug_data;	// add/remove nodes you use

	void debug_add_node(Node* node) {
		debug_data.push_back(node);
	}
	void debug_remove_node(Node* node) {
		auto it = std::find(debug_data.begin(), debug_data.end(), node);
		if (it == debug_data.end())
			cout << "Node does not exist\n";
		else
			debug_data.erase(it);
	}

public:

    void delete_node(Node* node) {
		debug_remove_node(node);
		--length;
		delete node;
	}

	void add_node(Node* node) {
		debug_add_node(node);
		++length;
	}

    Node* delete_and_link(Node* cur){
        Node* ret = cur->prev;
        link(cur->prev, cur->next);
        delete_node(cur);
        return ret;
    }

    print_reversed() {
        for(Node *cur = tail; cur; cur = cur->prev){
            cout << cur->data << " ";
        }
        cout << "\n";
    }

    void link(Node* first, Node* second){
        if(first)
            first->next = second;
        if(second)
            second->prev = first;
    }

    void insert_end(int value){
        Node* item = new Node(value);

        if(!head)
            head = tail = item;
        else{
            link(tail, item);
            tail = item;
        }
    }

    void delete_all_nodes_with_key(int value){
        if (!length){
            return;
        } 
        for(Node *cur = head; cur;){
            if(cur->data == value){
                cur = delete_and_link(cur);
                if(!cur->next)
                    tail = cur;
            } 
            else    
                cur= cur->next;
        }
    }

    void delete_even_positions(){
        if(length <= 1)
            return;

        for(Node *cur= head; cur && cur->next; cur = cur->next){
            delete_and_link(cur->next);
            if(!cur->next){
                tail = cur;
            }else
                cur = cur->next;
        }
    }

    void delete_odd_positions(){
        if(!length)
            return;
        
        for(Node* cur = head; cur: cur = cur->next){
            cur = delete_and_link(cur);
            if(!cur->next)
                tail = cur;
            else   
                cur = cur->next;
        }
    }

    typedef Node* Lnode;
    bool is_palindrome(){
        if(length <= 1)
            return ture;
        int len = length/2;
        Lnode start {head}, end {tail};
        while(len--){
            if(start->data != end->data)
                return false;
            start = start->next;
            end = end->prev;
        }
        return true;
    }

    int middle_value(){
        Node *h = head, *t = tail;
        while(h != t && h->next != t)
            h = h->next, t = t->prev;
        return t->data;
    }

    int middle_value2(){
        assert(head);

        Node *slow = head, *fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data;
    }

    get_nth(int n){
        int cnt = 0;
        for(Node* cur = head; cur; cur = cur->next)
            if(++cnt == n)
                return cur;
        return nullptr;
    }

    get_nth_back(int n){
        int cnt = 0;
        for(Node* cur = tail; cur; cur = cur->prev)
            if(++cnt == n)
                return cur;
        return nullptr;
    }

    swap_kth1(int k){
        Node *first = get_nth(k);
        Node *last = get_nth_back(k);

        if(first == last)
            return;

        if(first->prev == last)
            swap(first, last);

        Node* first_prev = first->prev;
        Node* first_next = first->next;

        Node *last_prev = last->prev;
        Node *last_next = last->next;

        if(first->next == last){
            link(first_prev, last);
            link(last, first);
            link(first, last_next);
        } else {
            link(first_prev, last);
            link(last, first_next);
            link(last_prev, first);
            link(first, last_next);
        }

        if( k == 1)
            swap(head, tail);
    }

    void swap_kth(int k){
        if(k > length)
            return;
        int k_back = length - k + 1;
        if(k_back == k)
            return;
        
        if(k > k_back)
            swap(k, k_back);

        Node* first = get_nth(k);
        Node* last = get_nth(k_back);

        Node* first_prev = first->prev;
        Node* first_next = first->next;

        Node *last_prev = last->prev;
        Node *last_next = last->next;

        if(k + 1 == k_back){
            link(first_prev, last);
            link(last, first);
            link(first, last_next);
        } else {
            link(first_prev, last);
            link(last, first_next);
            link(last_prev, first);
            link(first, last_next);
        }

        if(k == 1)
            swap(head, tail);
    }

    void reverse(){
        if(length < 1)
            return;

        Node *first = head, *second = head->next;

        while(second){
            Node *first_ = second, *second_ = second->next;

            link(second, first);
            first = first_;
            second = second_;
        }
        swap(head, tail);
        head->prev = tail->next = nullptr;

    }

    void merge_2sorted_lists(LinkedList &other){
        if(!other.head)
            return;

        if(head){
            Node* cur1 = head;
            Node *cur2 = other.head;
            Node* last {};
            head = nullptr;

            while(cur1 && cur2){
                Node* next { };
                if(cur1->data <= cur2->data){
                    next = cur1;
                    cur1 = cur1->next;
                } else {
                    next = cur2;
                    cur2 = cur2->next;
                }
                link(last, next);
                last = next;
                if(!head)
                    head = last;
            }
            if(cur2){
                tail = other.tail;
                link(last, cur2);
            } else if(cur1){
                link(last, cur1);
            }
        } else {
            head = other.head;
            tail = other.tail;
        }

        length += other.length;
        other.head = other.tail = nullptr;
        other.length = 0;
    }


}


int main(){

}

