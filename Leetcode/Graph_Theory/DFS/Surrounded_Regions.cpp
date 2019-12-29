class Solution {
public:
    int n,m;
    void solve(vector<vector<char>>& board) {
        if(board.size() < 1) return;
        n = board.size(),m = board[0].size();
        for(int i = 0;i < n;i++){
            dfs(i,0,board);
            dfs(i,m - 1,board);
        }
        for(int i = 0;i < m;i++){
            dfs(0,i,board);
            dfs(n - 1,i,board);
        }
        for(int i = 0;i < n;i++){
           for(int j = 0;j < m;j++){
               if(board[i][j] == 'O') board[i][j] = 'X';
               if(board[i][j] == '$') board[i][j] = 'O';
           }
        } 
    }
    
    void dfs(int i,int j,vector<vector<char>>& board){
        if(i < 0 or i > n - 1 or j < 0 or j > m - 1) return;
        if(board[i][j] == 'O'){
            board[i][j] = '$';
            dfs(i - 1,j,board);
            dfs(i + 1,j,board);
            dfs(i,j - 1,board);
            dfs(i,j + 1,board);
        }
    }
};
