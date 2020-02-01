class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int,int>>s;
        vector<int>ans(nums.size(),-1);
        int i = 0;
        for(auto x:nums){
            while(!s.empty() and x > s.top().first){
                ans[s.top().second] = x;
                s.pop();
            }
            s.push({x,i++});
        }
        for(auto x:nums){
            while(!s.empty() and x > s.top().first){
                ans[s.top().second] = x;
                s.pop();
            }
        }
        return ans;
    }
};
