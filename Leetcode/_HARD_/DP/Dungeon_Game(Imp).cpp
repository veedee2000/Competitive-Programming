class Solution {
public:
    vector<vector<int>>dp;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(!dungeon.size()) return 0;
        int m = dungeon.size();
        int n = dungeon[0].size();
        dp.resize(m,vector<int>(n,0));
        return f(0,0,dungeon);
    }
    
    int f(int i,int j,vector<vector<int>>& dungeon){
        if(i >= dungeon.size() or j >= dungeon[0].size()) return INT_MAX;
        if(dp[i][j]) return dp[i][j];
        int next = min(f(i + 1,j,dungeon),f(i,j + 1,dungeon));
        next = (next == INT_MAX) ? 1 : next;
        return dp[i][j] = max(next - dungeon[i][j],1);
    }
};
