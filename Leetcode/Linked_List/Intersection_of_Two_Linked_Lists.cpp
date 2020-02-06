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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0,sizeB = 0;
        ListNode* temp = headA;
        while(temp) temp = temp -> next,sizeA++;
        temp = headB;
        while(temp) temp = temp -> next,sizeB++;
        while(sizeA < sizeB) headB = headB -> next,sizeB--;
        while(sizeA > sizeB) headA = headA -> next,sizeA--;
        while(headA and headB){
            if(headA == headB) return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return NULL;
    }
};
