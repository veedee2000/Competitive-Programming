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
        ListNode* ans = head;
        bool c = 0;
        while(head){
            if(c) ans = ans -> next;
            head = head -> next;
            c = !c;
        }
        return ans;
    }
};
