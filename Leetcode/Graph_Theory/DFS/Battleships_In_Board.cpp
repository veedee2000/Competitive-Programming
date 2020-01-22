class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                if(dfs(i,j,board)) ++ans;
            }
        }
        return ans;
    }
    
    bool dfs(int i,int j,vector<vector<char>>& board){
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size()) return 0;
        if(board[i][j] == 'X'){
            board[i][j] = '.';
            dfs(i,j + 1,board);
            dfs(i,j - 1,board);
            dfs(i + 1,j,board);
            dfs(i - 1,j,board);
            return 1;
        }
        return 0;
    }
};
