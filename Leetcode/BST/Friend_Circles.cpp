class Solution {
public:
    bool check[300];
    int n;
    int findCircleNum(vector<vector<int>>& m) {
        n = m.size();
        int ans = 0;
        memset(check,0,sizeof(check));
        if(n == 0) return 0;
        for(int i = 0;i < n;i++){
            if(!check[i]) {dfs(i, m); ++ans;}
        }
        return ans;
    }
    
    void dfs(int i, vector<vector<int>>& m){
        check[i] = 1;
        for(int j = 0;j < n;j++){
            if(m[i][j] == 1 and !check[j]) dfs(j, m); 
        }
    }
};
