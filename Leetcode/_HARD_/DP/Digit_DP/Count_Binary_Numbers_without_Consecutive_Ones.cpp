class Solution {
public:
    vector<vector<vector<int>>>dp;
    vector<int>v;
    int findIntegers(int num) {
        for(int i = 0;i < 32;i++){
            if((1 << i) > num) break;
            v.push_back(((1 << i) & num) > 0);
        }
        reverse(v.begin(),v.end());
        dp.resize(v.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return f(0,0,0);
    }
    
    int f(int i,bool prevOne,bool smaller){
        if(i == v.size()) return 1;
        if(dp[i][prevOne][smaller] != -1) return dp[i][prevOne][smaller];
        int limit;
        if(!smaller){
            limit = v[i];
        }
        else{
            limit = 1;
        }
        int ans;
        if(limit == 0) ans = f(i + 1,0,smaller);
        else ans = f(i + 1,0,1) + ((!prevOne) ? f(i + 1,1,smaller) : 0);
        return dp[i][prevOne][smaller] = ans;
    }
};
