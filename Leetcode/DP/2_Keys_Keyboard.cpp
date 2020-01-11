const int INF = 10000000;

class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int minSteps(int n) {
        this -> n = n;
        if(n == 1) return 0;
        dp.resize(n + 1,vector<int>(n + 1, -1));
        return 1 + f(1,1);
    }
    
    int f(int i,int paste){
        if(i > n) return INF;
        if(i == n) return 0;
        if(dp[i][paste] != -1) return dp[i][paste];
        return dp[i][paste] = 1 + min(f(i + paste,paste),1 + f(i + i,i));
    }
};
