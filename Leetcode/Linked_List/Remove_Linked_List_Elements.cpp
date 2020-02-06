/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = head;
        bool c = 0;
        while(head and head -> val == val){
            ListNode* temp = head;
            head = head -> next;
            temp = NULL;
            delete temp;
        }
        if(!head) return NULL;
        ListNode* temp = head;
        while(temp){
            while(temp -> next and temp -> next -> val == val){
                ListNode* node = temp -> next;
                temp -> next = temp -> next -> next;
                node = NULL;
                delete node;
            }
            temp = temp -> next;
        }
        return head;
    }
};
