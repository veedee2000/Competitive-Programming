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
        if(!head) return head;
        ListNode *ans = head,*node;
        head = head -> next;
        ans -> next = NULL;
        while(head){
            node = head;
            head = head -> next;
            node -> next = ans;
            ans = node;
        }
        return ans;
    }
};
