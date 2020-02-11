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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *t = head,*t1 = NULL;
        int sz = 0;
        bool c = 0;
        while(t) sz++,t = t -> next;
        t = head;
        while(sz >= k){
            int val = k;
            ListNode *headNow = t;
            while(--val) t = t -> next;
            ListNode *temp = t -> next;
            t -> next = NULL;
            headNow = reverse(headNow);
            if(t1) t1 -> next = headNow;
            val = k;
            t = headNow;
            while(--val) t = t -> next;
            t -> next = temp;
            t1 = t;
            t = t -> next;
            if(!c){
                head = headNow;
                c = !c;
            }
            sz -= k;
        }
        return head;
    }
    
    ListNode* reverse(ListNode* head){
        if(!head or !head -> next) return head;
        ListNode *temp = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return temp;
    }
    
};
