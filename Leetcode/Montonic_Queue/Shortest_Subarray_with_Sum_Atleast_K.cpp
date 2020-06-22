class Solution {
    
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix = 0, ans = n + 1;
        deque<vector<int>>d;
        d.push_back({0,-1});
        for(int i = 0;i < n;i++){
            prefix += nums[i];
            while(!d.empty() and prefix - d.front()[0] >= k){
                ans = min(ans, i - d.front()[1]);
                d.pop_front();
            }
            while(!d.empty() and prefix <= d.back()[0]) d.pop_back();
            d.push_back({prefix, i});
        }
        
        return ans == n + 1 ? -1 : ans;
    }
};
