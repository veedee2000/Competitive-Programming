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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        int count = 0;
        ListNode* head = new ListNode(0);
        ListNode* l = head;
        while(l1 or l2){
            if(!l1) count = -1;
            if(!l2) count = 1;
            if(!count){
                if(l1 -> val < l2 -> val){
                    l -> next = new ListNode(l1 -> val);
                    l = l -> next;
                    l1 = l1 -> next;
                }
                else{
                    l -> next = new ListNode(l2 -> val);
                    l = l -> next;
                    l2 = l2 -> next;
                }
            }
            else if(count < 0){
                l -> next = new ListNode(l2 -> val);
                l = l -> next;
                l2 = l2 -> next;
            }
            else{
                l -> next = new ListNode(l1 -> val);
                l = l -> next;
                l1 = l1 -> next;
            }
        }
        return head -> next;
    }
};
