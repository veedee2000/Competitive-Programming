class Solution {
public:
    vector<int>nums;
    set<int>s;
    vector<vector<vector<int>>>dp;
    int atMostNGivenDigitSet(vector<string>& D, int n) {
        for(auto x:D) s.insert(stoi(x));
        while(n){
            nums.push_back(n % 10);
            n /= 10;
        }
        reverse(nums.begin(),nums.end());
        dp.resize(nums.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return f(0,0,0) - 1;
    }
    
    int f(int i,bool before,bool smaller){
        if(i == nums.size()) return 1;
        if(dp[i][before][smaller] != -1) return dp[i][before][smaller];
        int limit = 9;
        if(!smaller) limit = nums[i];
        int ans = 0;
        if(!before) ans += f(i + 1,0,1);
        for(auto x:s){
            if(x < limit) ans += f(i + 1,1,1);
            else break;
        }
        if(s.count(limit)) ans += f(i + 1,1,smaller);
        return dp[i][before][smaller] = ans;
    }
};
