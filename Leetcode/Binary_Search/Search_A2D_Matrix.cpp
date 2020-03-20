class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return 0;
        int l = 0,r = matrix.size() * matrix[0].size() - 1,m,x,y;
        while(l <= r){
            if(l == r){
                x = l / matrix[0].size();
                y = l % matrix[0].size();
                return (matrix[x][y] == target);
            }
            m = l + (r - l) / 2;
            x = m / matrix[0].size();
            y = m % matrix[0].size();
            if(matrix[x][y] == target) return 1;
            if(matrix[x][y] < target) l = m + 1;
            else r = m - 1;
        }
        return 0;
    }
};
