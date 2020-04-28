class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int val = 0,ans = 0;
        for(int i = 0;i < k;i++) val += customers[i];
        for(int i = k;i < customers.size();i++) val += !grumpy[i] ? customers[i] : 0;
        ans = val;
        for(int i = 0;i < customers.size() - k;i++){
            val += (grumpy[i] ? -customers[i] : 0) + (grumpy[i + k] ? customers[i + k] : 0);
            ans = max(ans,val);
        }
        return ans;
    }
};
