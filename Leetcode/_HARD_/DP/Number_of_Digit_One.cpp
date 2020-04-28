class Solution {
public:
    vector<int>nums;
    vector<vector<vector<int>>>dp;
    int countDigitOne(int n) {
        while(n){
            nums.push_back(n % 10);
            n /= 10;
        }
        reverse(nums.begin(),nums.end());
        
        int ans = 0;
        for(int i = 1;i <= nums.size();i++){
            dp.clear();
            dp.resize(nums.size(),vector<vector<int>>(i + 1,vector<int>(2,-1)));
            ans += i * f(0,i,0);
        }
        return ans;
    }
    
    int f(int i,int num,bool smaller){
        if(i == nums.size()) return (num == 0);
        if(num < 0) return 0;
        if(dp[i][num][smaller] != -1) return dp[i][num][smaller];
        int limit = 9;
        if(!smaller) limit = nums[i];
        int ans = 0;
        for(int digit = 0;digit < limit;digit++){
            if(digit == 1) ans += f(i + 1,num - 1,1);
            else ans += f(i + 1,num,1);
        }
        if(limit == 1) ans += f(i + 1,num - 1,smaller);
        else ans += f(i + 1,num,smaller);
        
        return dp[i][num][smaller] = ans;
    }
};
