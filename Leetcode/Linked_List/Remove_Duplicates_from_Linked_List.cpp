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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *ans = head;
        while(head -> next){
            if(head -> val != head -> next -> val) head = head -> next;
            while(head -> next and head -> val == head -> next -> val){
                ListNode *temp = head -> next;
                head -> next = head -> next -> next;
                temp = NULL;
                delete temp;
            }
        }
        return ans;
    }
};
