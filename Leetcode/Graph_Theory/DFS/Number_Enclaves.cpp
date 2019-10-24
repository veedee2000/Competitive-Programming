class Solution {
public:
    bool check[510][510],turn;
    int ans = 0,n,m,val;
    
    int numEnclaves(vector<vector<int>>& a) {
        n = a.size(), m = a[0].size();
        memset(check,0,sizeof(check));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                turn = 0;
                if(!check[i][j]){
                    val = dfs(i,j,a);
                    if(!turn) ans+=val;
                }
            }
        }
        return ans;
    }
    
    int dfs(int i, int j, vector<vector<int>>& a){
        int v1=0,v2=0,v3=0,v4=0;
        check[i][j] = 1;
        if(!a[i][j]) return 0;
        if(i == n-1 or j == m-1 or i == 0 or j == 0) {turn = 1;}
        if(i > 0 and !check[i-1][j] and a[i-1][j]) v1 = dfs(i-1,j,a);
        if(i < n-1 and !check[i+1][j] and a[i+1][j]) v2 = dfs(i+1,j,a);
        if(j > 0 and !check[i][j-1] and a[i][j-1]) v3 = dfs(i,j-1,a);
        if(j < m-1 and !check[i][j+1] and a[i][j+1]) v4 = dfs(i,j+1,a);
        return 1 + v1 + v2 + v3 + v4;
    }
    
};
