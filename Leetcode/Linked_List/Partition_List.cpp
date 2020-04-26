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
    ListNode* partition(ListNode* head, int x) {
        ListNode *headBefore = new ListNode(0), *headAfter = new ListNode(0);
        ListNode *t1 = headBefore, *t2 = headAfter;
        while(head){
            if(head -> val < x){
                t1 -> next = head;
                t1 = t1 -> next;
            }
            else{
                t2 -> next = head;
                t2 = t2 -> next;
            }
            head = head -> next;
        }
        t2 -> next = NULL;
        t1 -> next = headAfter -> next;
        return headBefore -> next;
    }
};
