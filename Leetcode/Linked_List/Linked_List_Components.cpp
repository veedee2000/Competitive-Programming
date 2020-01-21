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
    unordered_map<int,int>mp;
    int numComponents(ListNode* head, vector<int>& G) {
        for(auto x:G) mp[x]++;
        int ans = 0,count = 0;
        while(head){
            if(mp.count(head -> val)){
                count++;
            }
            else{
                if(count){
                    count = 0;
                    ans++;
                }
            }
            head = head -> next;
        }
        if(count) ++ans;
        return ans;
    }
};
