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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* traverse = head;
        int sz = 0;
        while(traverse) traverse = traverse -> next,sz++;
        vector<int>ans(sz,0);
        stack<pair<int,int>>s;
        int i = 0;
        while(head){
            while(!s.empty() and s.top().first < head -> val){
                ans[s.top().second] = head -> val;
                s.pop();
            }
            s.push({head -> val,i++});
            head = head -> next;
        }
        return ans;
    }
};
