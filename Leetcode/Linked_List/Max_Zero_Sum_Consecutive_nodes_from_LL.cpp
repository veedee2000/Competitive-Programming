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
        vector<int>v;
        while(head){
            v.push_back(head -> val);
            int sum = 0;
            for(int i = v.size() - 1;i >= 0;i--){
                sum += v[i];
                if(sum == 0) v.erase(v.begin() + i,v.end());
            }
            head = head -> next;
        }
        head = NULL;
        ListNode *temp;
        for(auto x:v){
            if(!head) head = new ListNode(x),temp = head;
            else temp -> next = new ListNode(x),temp = temp -> next;
        }
        return head;
    }
};
