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
    bool isPalindrome(ListNode* head) {
        string s1 = "",s2;
        while(head) s1.push_back(head -> val + '0'),head = head -> next;
        s2 = s1;
        reverse(s1.begin(),s1.end());
        return (s1 == s2);
    }
};
