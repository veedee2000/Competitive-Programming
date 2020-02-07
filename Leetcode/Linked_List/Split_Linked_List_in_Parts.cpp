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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int sz = 0;
        vector<ListNode*>ans;
        ListNode *temp = root;
        while(temp) temp = temp -> next,sz++;
        int q = sz / k,r = sz % k;
        while(k--){
            int size = 0;
            size += q;
            if(r > 0) size++,r--;
            int val = size;
            ListNode *temp = root;
            while(val--){
                root = root -> next;
            }
            val = size;
            ListNode* t = temp;
            while(--val > 0){
                t = t -> next;
            }
            if(!temp) ans.push_back(NULL);
            else{
                t -> next = NULL;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
