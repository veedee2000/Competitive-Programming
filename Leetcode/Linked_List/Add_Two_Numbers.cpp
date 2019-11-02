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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* Element = head;
        int val1,val2,val = 0;
        while(l1 or l2 or val > 0){
            val1 = (l1 ? l1 -> val : 0);
            val2 = (l2 ? l2 -> val : 0);
            l1 = (l1 ? l1 -> next : NULL);
            l2 = (l2 ? l2 -> next : NULL);
            val += val1 + val2;
            Element -> next = new ListNode(val % 10);
            Element = Element -> next;
            val = val / 10;
        }
        return head -> next;
    }
};
