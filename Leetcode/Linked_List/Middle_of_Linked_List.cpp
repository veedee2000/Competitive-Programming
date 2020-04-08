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
    ListNode* middleNode(ListNode* head) {
        ListNode* t = head;
        int sz = 0;
        while(t) sz++,t = t -> next;
        sz = sz / 2;
        t = head;
        while(sz--){
            t = t -> next;
        }
        return t;
    }
};
