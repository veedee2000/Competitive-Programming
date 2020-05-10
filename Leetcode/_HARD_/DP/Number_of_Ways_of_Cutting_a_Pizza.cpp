class Solution {
    
    const int mod = 1e9 + 7;
    
public:
    vector<vector<vector<int>>>dp;
    
    int n,m;
    
    int ways(vector<string>& pizza, int k) {
        m = pizza.size(),n = pizza[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return f(0,0,k - 1,pizza);
    }
    
    int f(int x,int y,int k,vector<string>& pizza){
        if(k == 0){
            for(int i = x;i < m;i++){
                for(int j = y;j < n;j++){
                    if(pizza[i][j] == 'A') return 1;
                }
            }
            return 0;
        }
        if(dp[x][y][k] != -1) return dp[x][y][k];
        long ans = 0;
        bool columnCheck = 0,rowCheck = 0;
        for(int col = y;col < n - 1;col++){
            if(!columnCheck){
                for(int row = x;row < m;row++){
                    if(pizza[row][col] == 'A') { columnCheck = 1; break; }
                }
            }
            if(columnCheck) ans = (ans + f(x,col + 1,k - 1,pizza)) % mod;
        }
        for(int row = x;row < m - 1;row++){
            if(!rowCheck){
                for(int col = y;col < n;col++){
                    if(pizza[row][col] == 'A') { rowCheck = 1; break; }
                }
            }
            if(rowCheck) ans = (ans + f(row + 1,y,k - 1,pizza)) % mod;
        }
        return dp[x][y][k] = ans;
    }
};
