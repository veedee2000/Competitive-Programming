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
    ListNode* reverseList(ListNode* head) {
        if(!head or !head -> next) return head;
        ListNode* temp = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return temp;
    }
};
