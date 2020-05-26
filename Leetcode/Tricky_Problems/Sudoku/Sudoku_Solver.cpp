class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int16_t> row(9,0), col(9,0), sub(9,0);
        
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    int shift = 1 << num;
                    row[i] |= shift;
                    col[j] |= shift;
                    sub[3 * (i / 3) + j / 3] |= shift;
                }
            }
        }
        bool solved = 0;
        f(0,0,solved,row,col,sub,board);
    }
    
    void f(int i,int j,bool& solved,vector<int16_t>& row, vector<int16_t>& col, vector<int16_t>& sub,vector<vector<char>>& board){
        
        if(solved) return;
        if(i == 9){
            solved = 1;
            return;
        }
        
        if(j == 9){
            f(i + 1,0,solved,row,col,sub,board);
            return;
        }
        
        if(board[i][j] == '.'){
            int num = 1, count = 9;
            while(count--){
                
                if(solved) return;
                
                if( (row[i] & num) or (col[j] & num) or (sub[3 * (i / 3) + j / 3] & num) ) { num <<= 1; continue; }
                
                row[i] |= num;
                col[j] |= num;
                sub[3 * (i / 3) + j / 3] |= num;
                f(i,j + 1,solved,row,col,sub,board);
                if(solved) board[i][j] = '0' + (9 - count);
                row[i] ^= num;
                col[j] ^= num;
                sub[3 * (i / 3) + j / 3] ^= num;
                num <<= 1;
            }
        }
        else f(i,j + 1,solved,row,col,sub,board);
    }
};
