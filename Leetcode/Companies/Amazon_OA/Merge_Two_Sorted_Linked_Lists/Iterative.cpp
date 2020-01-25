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
        ListNode* traverse = new ListNode(0);
        ListNode* head = traverse;
        
        while(l1 and l2){
            if(l1 -> val < l2 -> val){
                traverse -> next = l1;
                l1 = l1 -> next;
            }
            else{
                traverse -> next = l2;
                l2 = l2 -> next;
            }
            traverse = traverse -> next;
        }
        
        if(l1) traverse -> next = l1;
        else traverse -> next = l2;
        return head -> next;
    }
};
