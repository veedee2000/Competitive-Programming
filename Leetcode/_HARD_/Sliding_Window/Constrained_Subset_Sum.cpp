class Solution {
public:
    
    int constrainedSubsetSum(vector<int>& dp, int k) {
        deque<pair<int,int>>d;
        for(int i = 0;i < dp.size();i++){
            dp[i] += d.size() ? max(d.back().first,0) : 0;
            while(d.size() and d.front().first < dp[i]) d.pop_front();
            d.push_front({dp[i],i});
            if(d.back().second == i - k) d.pop_back();
        }
        int ans = dp[0];
        for(auto x:dp) ans = max(ans,x);
        return ans;
    }
};
