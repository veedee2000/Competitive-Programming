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
    int getDecimalValue(ListNode* head) {
        string ans = "";
        while(head){
            ans.push_back((char) head -> val + '0');
            head = head -> next;
        }
        int ret = 0,val = binExp(2,ans.size() - 1);
        for(auto x:ans){
            if(x == '1') ret += val;
            val /= 2;
        }
        return ret;
    }
    
    int binExp(int a,int exp){
        if(exp == 0) return 1;
        if(exp & 1) return a * binExp(a,exp / 2) * binExp(a,exp / 2);
        return binExp(a,exp / 2) * binExp(a,exp / 2);
    }
};
