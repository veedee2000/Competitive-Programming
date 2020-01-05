class Solution {
public:
    vector<int>row,column;
    int countServers(vector<vector<int>>& grid) {
        int val = 0,ans = 0;
        row.resize(grid.size(),0);
        column.resize(grid[0].size(),0);
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j]) row[i]++,column[j]++,val++;
            }
        }
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j]){
                    if(row[i] == 1 and column[j] == 1) ++ans;
                }
            }
        }
        return (val - ans);
    }
};
