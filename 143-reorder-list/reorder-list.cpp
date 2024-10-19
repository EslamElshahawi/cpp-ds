/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* right = slow->next;
        slow->next = NULL;
        ListNode* cur = right;
        ListNode* prev = NULL;
        ListNode* next = new ListNode(0);
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        right = prev;
        ListNode* left = head;
        while(right){
            ListNode* temp = left->next;
            left->next = right;
            ListNode* tempr = right->next;
            right->next = temp;
            right = tempr;
            left = temp;
        }
        
    }
};