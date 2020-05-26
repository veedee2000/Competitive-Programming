class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bitset<9>> row(9,0), col(9,0), sub(9,0);
        
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    bitset<9>shift(1 << num);
                    
                    
                    row[i] |= shift;
                    col[j] |= shift;
                    sub[3 * (i / 3) + j / 3] |= shift;
                }
            }
        }
        return true;
    }
};
