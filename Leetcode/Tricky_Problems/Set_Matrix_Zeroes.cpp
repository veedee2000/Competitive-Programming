class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(!matrix.size()) return;
        int m = matrix.size(),n = matrix[0].size();
        bool firstRowZero = 0,firstColumnZero = 0;
        
        for(int j = 0;j < n;j++) if(matrix[0][j] == 0) {firstRowZero = 1; break;}
        for(int i = 0;i < m;i++) if(matrix[i][0] == 0) {firstColumnZero = 1; break;}
        
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                if(matrix[i][j] == 0) matrix[i][0] = 0,matrix[0][j] = 0;
            }
        }
        
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                if(matrix[i][0] == 0 or matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        
        if(firstRowZero) for(int j = 0;j < n;j++) matrix[0][j] = 0;
        if(firstColumnZero) for(int i = 0;i < m;i++) matrix[i][0] = 0;
    }
};
