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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast,*slow,*start;
        start = fast = slow = head;
        bool c = 0;
        while(slow and fast and fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow){
                fast = head;
                while(start != slow){
                    start = startt -> next;
                    slow = slow -> next;
                }
                return start;
            }
        }
        return NULL;
    }
};
