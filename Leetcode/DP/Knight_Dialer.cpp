const int mod = 1000000007;

class Solution {
public:
    vector<vector<int>>dp;
    vector<vector<int>>moves;
    int knightDialer(int N) {
        int ans = 0;
        moves = {{4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4}};
        dp.resize(10,vector<int>(N + 1, -1));
        for(int i = 0;i < 10;i++){
            if(i == 5) continue;
            ans = (ans + f(i,N)) % mod;
        }
        if(N == 1) ++ans;
        return ans;
    }
    
    int f(int i,int N){
        if(N == 1) return 1;
        if(dp[i][N] != -1) return dp[i][N];
        int ans = 0;
        for(int j = 0;j < moves[i].size();j++){
            ans = (ans + f(moves[i][j],N - 1)) % mod;
        }
        return dp[i][N] = ans;
    }
};
