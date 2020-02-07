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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head -> next) return head;
        ListNode *ret = head -> next;
        ListNode* pre = NULL;
        while(head and head -> next){
            ListNode* temp = head -> next;
            head -> next = head -> next -> next;
            temp -> next = head;
            if(pre) pre -> next = temp,pre = pre -> next -> next;
            else pre = temp,pre = pre -> next;
            head = head -> next;
        }
        return ret;
    }
};
