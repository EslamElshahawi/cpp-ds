#include <iostream>
#include <cassert>
#include <climits>

#include <vector>		// for debug
#include <algorithm>
#include <sstream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int data) : data(data) {}
	~Node() {
		cout << "Destroy value: " << data <<" at address "<< this<< "\n";
	}
};

class LinkedList {
private:
	Node *head;
	Node *tail;
	int length = 0;	// let's maintain how many nodes

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

	// Below 2 deletes prevent copy and assign to avoid this mistake
	LinkedList() {
	}
	LinkedList(const LinkedList&) = delete;
	LinkedList &operator=(const LinkedList &another) = delete;

	void debug_print_address() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur << "," << cur->data << "\t";
		cout << "\n";
	}

	void debug_print_node(Node* node, bool is_seperate = false) {
		if (is_seperate)
			cout << "Sep: ";
		if (node == nullptr) {
			cout << "nullptr\n";
			return;
		}
		cout << node->data << " ";
		if (node->next == nullptr)
			cout << "X ";
		else
			cout << node->next->data << " ";

		if (node == head)
			cout << "head\n";
		else if (node == tail)
			cout << "tail\n";
		else
			cout << "\n";
	}
	void debug_print_list(string msg = "") {
		if (msg != "")
			cout << msg << "\n";
		for (int i = 0; i < (int) debug_data.size(); ++i)
			debug_print_node(debug_data[i]);
		cout << "************\n"<<flush;
	}

	string debug_to_string() {
		if (length == 0)
			return "";
		ostringstream oss;
		for (Node* cur = head; cur; cur = cur->next) {
			oss << cur->data;
			if (cur->next)
				oss << " ";
		}
		return oss.str();
	}

	void debug_verify_data_integrity() {
		if (length == 0) {
			assert(head == nullptr);
			assert(tail == nullptr);
		} else {
			assert(head != nullptr);
			assert(tail != nullptr);
			if (length == 1)
				assert(head == tail);
			else
				assert(head != tail);
			assert(!tail->next);
		}
		int len = 0;
		for (Node* cur = head; cur; cur = cur->next, len++)
			assert(len < 10000);	// Consider infinite cycle?
		assert(length == len);
		assert(length == (int)debug_data.size());
	}

	////////////////////////////////////////////////////////////

	void print() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}

	// These 2 simple functions just to not forget changing the vector and length
	void delete_node(Node* node) {
		debug_remove_node(node);
		--length;
		delete node;
	}

	void add_node(Node* node) {
		debug_add_node(node);
		++length;
	}

	void insert_end(int value) {
		Node* item = new Node(value);
		add_node(item);

		if (!head){
			head = item;
            tail = head;
        }
		else
			tail->next = item, tail = item;
	}

    void insert_front(int value){
        Node* item = new Node(value);
        add_node(item);
        item->next = head;
        head = item;

        if(length == 1)
            tail = head;
        
        debug_verify_data_integrity();
    }

    void delete_front(){
        assert(length);
        Node* cur  = head->next;
        delete_node(head);
        head = cur;

        debug_verify_data_integrity();
    }

    Node* get_nth(int n){
        int cnt = 0;
        for(Node* cur = head; cur; cur = cur->next){
            if(++cnt == n){
                return cur;
            }
        }
        return nullptr;
    }

    Node* get_nth_back(int n){
        if(length < n)
            return nullptr;
        return get_nth(length - n + 1);
    }

    bool is_same1(const LinkedList &other){
        Node *h1 = head, *h2 = other.head;

        while(h1 && h2){
            if(h1->data != h2->data)
                return false;
            
            h1 = h1->next;
            h2 = h2->next;
        }
        

        return !h1 && !h2;
    }

    bool is_same(const LinkedList &other){
        if (length != other.length)
            return false;

        Node* otherH = other.head;
        for(Node* curH = head; curH; curH = curH->next, otherH = otherH->next)
            if(curH->data != otherH->data)
                return false;
        return true;
    }

    void delete_first() {
		if (head) {
			//Move to next in the list
			// and remove current
			Node* cur = head;
			head = head->next;
			delete_node(cur);

			if (!head)	// data integrity!
				tail = nullptr;
			debug_verify_data_integrity();
		}
	}

    void delete_last() {
		if (length <= 1) {
			delete_first();
			return;
		}
		// Get the node before tail: its order is length-1 node
		Node* previous = get_nth(length - 1);

		delete_node(tail);
		tail = previous;
		tail->next = nullptr;

		debug_verify_data_integrity();
	}

	void delete_nth_node(int n) {
		if (n < 1 || n > length)
			cout << "Error. No such nth node\n";
		else if (n == 1)
			delete_first();
		else {
			// Connect the node before nth with node after nth
			Node* before_nth = get_nth(n - 1);
			Node* nth = before_nth->next;
			bool is_tail = nth == tail;
			// connect before node with after
			before_nth->next = nth->next;
			if (is_tail)
				tail = before_nth;

			delete_node(nth);

			debug_verify_data_integrity();
		}
	}

    void delete_next_node(Node* node){
        assert(node);
        Node* to_delete = node->next;
        bool is_tail = to_delete == tail;

        node->next = node->next->next;
        delete_node(to_delete);
        if(is_tail)
            tail = node;
    }

    void delete_node_with_key(int value){
        if(!length)
            cout << "Empty list \n";
        else if(head->data == value)
            delete_first();
        else {
            for(Node* cur = head, *prv = nullptr; cur; prv = cur, cur = cur->next){
                if(cur->data == value){
                    delete_next_node(prv);
                    return;
                }
            }
            cout << "value not found! \n";
        }
        debug_verify_data_integrity();
        
    }

    void swap_pairs() {
        for(Node* cur = head; cur; cur = cur->next){
            if(cur->next){
                swap(cur->data, cur->next->data);
                cur = cur->next;
            }
        }
    }

    void reverse(){
        if (length <= 1)
            return;
        tail = head;
        Node* prv = head;
        head = head->next;

        while(head){
            Node* next = head->next;
            head->next = prv;
            
            prv = head;
            head = next;
        }
        head = prv;
        tail->next = nullptr;

        debug_verify_data_integrity();
    }

    void delete_even_positions(){
        if(length <= 1)
            return;
        
        for(Node *cur = head->next, *prv = head; cur;){
            delete_next_node(prv);
            if(!prv->next)
                break;
            cur = prv->next->next;
            prv = prv->next;

        }
        debug_verify_data_integrity();
    }

    void embed_after(Node* node, int value){
        Node* item = new Node(value);
        length++;
        debug_add_node(item);

        item->next = node->next;
        node->next = item;
    }

    void insert_sorted(int value){
        if(!length || value <= head->data)
            insert_front(value);
        else if(tail->data <= value)
            insert_end(value);
        else {
            for(Node *cur = head, *prv = nullptr; cur; prv = cur, cur = cur->next){
                if (value <= cur->data)
                    embed_after(prv, value);
                    break;
            }
        }

    }

	////////////////////////////////////////////////////////////
    ~LinkedList(){
        while(head){
            Node* current = head->next;
            delete head;
            head = current;
        }
    }

};

void test1() {
	cout << "\n\ntest1\n";
	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	// some actions
	list.print();

	string expected = "1 2 3";
	string result = list.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " <<
				expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	list.debug_print_list("********");
}

void test2() {
	cout << "\n\ntest2\n";
	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
    list.insert_end(4);
	// some actions
	list.print();

	string expected = "1 2 3 4";
	string result = list.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	list.debug_print_list("********");
}


int main() {
	test1();
	test2();
	//test3();

	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

	return 0;
}