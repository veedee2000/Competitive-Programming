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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode *t = head;
        while(t) sz++,t = t -> next;
        n = sz - n;
        if(n == 0) return head -> next;
        t = head;
        while(--n > 0) t = t -> next;
        ListNode *node = t -> next;
        t -> next = t -> next -> next;
        node = NULL;
        delete node;
        return head;
    }
};
