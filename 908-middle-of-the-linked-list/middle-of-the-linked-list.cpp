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
    ListNode* middleNode(ListNode* head) {
        ListNode* current = head;
        int length = 0;
        while(current){
            length++;
            current = current->next;
        }
        current = head;
        int mid = length/2 + 1;
        for(int i = 1; i < mid; i++){
            current = current->next;
        }
        return current;
    }
};