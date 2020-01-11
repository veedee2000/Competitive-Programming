class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix){
        if(!matrix.size()) return 0;
        int ans = 0;
        for(int i = 0;i < matrix.size();i++){
           ans = max(ans,matrix[i][0] - '0'); 
        }
        
        for(int j = 0;j < matrix[0].size();j++){
           ans = max(ans,matrix[0][j] - '0'); 
        }
        
        for(int i = 1;i < matrix.size();i++){
            for(int j = 1;j < matrix[0].size();j++){
                if(matrix[i][j] == '1'){
                    matrix[i][j] = (char)(((min({matrix[i - 1][j],matrix[i][j - 1],matrix[i - 1][j - 1]}) - '0') + 1) + '0');
                    ans = max(ans,matrix[i][j] - '0');
                }
            }
        }
        return ans * ans;
    }
};
