/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
    ListNode* reverse(ListNode* node){
        if(!node or !node -> next) return node;
        ListNode* temp = reverse(node -> next);
        node -> next -> next = node;
        node -> next = NULL;
        return temp;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if(!head or !head -> next) return 1;
        ListNode *slow = head, *fast = head -> next;
        while(fast and fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* rev = slow -> next;
        rev = reverse(rev);
        while(rev){
            if(rev -> val != head -> val) return 0;
            rev = rev -> next;
            head = head -> next;
        }
        return 1;
    }
};
