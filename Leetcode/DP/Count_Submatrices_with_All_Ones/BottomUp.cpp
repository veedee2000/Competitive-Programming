class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for(int i = 0;i < m;i++) ans += matrix[i][0];
        for(int j = 0;j < n;j++) ans += matrix[0][j];
        ans -= matrix[0][0];
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                if(matrix[i][j]) matrix[i][j] = 1 + min({matrix[i - 1][j],matrix[i][j - 1],matrix[i - 1][j - 1]});
                
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};
