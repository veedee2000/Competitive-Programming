class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(!matrix.size()) return;
        int n = matrix.size();
        for(int i = 0;i < n / 2;i++){
            for(int j = i;j < n - i - 1;j++){
                swap(matrix[i][j],matrix[j][n - i - 1]);
                swap(matrix[i][j],matrix[n - i - 1][n - j - 1]);
                swap(matrix[i][j],matrix[n - j - 1][i]);
            }
        }
    }
};
