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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return NULL;
        ListNode *temp = removeZeroSumSublists(head -> next);
        head -> next = temp;
        temp = head;
        int sum = 0;
        while(temp){
            sum += temp -> val;
            if(sum == 0){
                while(head != temp) head = head -> next;
                head = head -> next;
                break;
            }
            temp = temp -> next;
        }
        return head;
    }
};
