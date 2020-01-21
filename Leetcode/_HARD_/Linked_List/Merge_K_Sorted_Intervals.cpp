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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int>ms;
        for(auto x:lists){
            while(x){
                ms.insert(x -> val);
                x = x -> next;
            }
        }
        
        ListNode* head = NULL,*temp;
        for(auto x:ms){
            if(!head){
                head = new ListNode(x);
                temp = head;
            }
            else{
                temp -> next = new ListNode(x);
                temp = temp -> next;
            }
        }
        return head;
    }
};
