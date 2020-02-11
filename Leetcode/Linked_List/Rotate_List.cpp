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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head -> next) return head;
        ListNode *t = head;
        int sz = 1;
        while(t -> next){
            sz++;
            t = t -> next;
        }
        t -> next = head;
        k = k % sz;
        k = sz - k;
        while(k--){
            t = t -> next;
        }
        ListNode *ans = t -> next;
        t -> next = NULL;
        return ans;
    }
};
