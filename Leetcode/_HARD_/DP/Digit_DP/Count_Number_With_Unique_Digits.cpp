class Solution {
public:
    vector<vector<vector<int>>>dp;
    vector<int>nums;
    int countNumbersWithUniqueDigits(int n) {
        int c = 0;
        if(n < 2) c = 1;
        if(n > 9) nums = {9,9,9,9,9,9,9,9,9,9};
        else{
            nums.push_back(1);
            while(n--) nums.push_back(0);
        }
        dp.resize(nums.size(),vector<vector<int>>((1 << 10),vector<int>(2,-1)));
        return f(0,0,0) - c;
    }
    
    int f(int i,int hash,bool smaller){
        if(i == nums.size()) return 1;
        if(dp[i][hash][smaller] != -1) return dp[i][hash][smaller];
        int limit = 9;
        if(!smaller) limit = nums[i];
        int ans = 0;
        for(int digit = 0;digit < limit;digit++){
            if((1 << digit) & hash) continue;
            if(hash == 0 and digit == 0) ans += f(i + 1,hash,1);
            else ans += f(i + 1,hash | (1 << digit),1);
        }
        if(hash == 0 and limit == 0) ans += f(i + 1,hash,smaller);
        else if(((1 << limit) & hash) == 0) ans += f(i + 1,hash | (1 << limit),smaller); 
        return dp[i][hash][smaller] = ans;
    }
};
