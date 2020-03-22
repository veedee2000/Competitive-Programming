class Solution {
public:
    unordered_map<int,int>dp;
    int desiredTotal,maxChoosableInteger;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal <= maxChoosableInteger) return 1;
        if(desiredTotal > (maxChoosableInteger * (maxChoosableInteger + 1)) / 2) return 0;
        this -> desiredTotal = desiredTotal;
        this -> maxChoosableInteger = maxChoosableInteger;
        return f(0,0);
    }
    
    bool f(int i,int total){
        if(total >= desiredTotal) return 0;
        if(dp.count(i)) return dp[i];
        bool ans = 0;
        for(int j = maxChoosableInteger;j > 0;j--){
            if(i & (1 << j)) continue;
            ans |= !f(i | (1 << j),total + j);
            if(ans == 1) break;
        }
        return dp[i] = ans;
    }
};
