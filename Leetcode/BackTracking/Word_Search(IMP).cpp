class Solution {
public:
    int m,n;
    vector<int>dr,dc;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(),n = board[0].size();
        dr = {-1,1,0,0},dc = {0,0,-1,1};
        vector<vector<bool>>b;
        b.resize(m,vector<bool>(n,0));
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                if(f(i,j,0,board,word,b)) return 1;
            }
        }
        return 0;
    }
    
    bool f(int i,int j,int pos,vector<vector<char>>& board, string& word,vector<vector<bool>>& b){
        if(pos == word.size()) return 1;
        if(i < 0 or i >= m or j < 0 or j >= n) return 0;
        if(board[i][j] != word[pos]) return 0;
        if(b[i][j]) return 0;
        b[i][j] = 1;
        for(int rc = 0;rc < 4;rc++){
            if(f(i + dr[rc],j + dc[rc],pos + 1,board,word,b)) return 1;
        }
        b[i][j] = 0;
        return 0;
    }
};
