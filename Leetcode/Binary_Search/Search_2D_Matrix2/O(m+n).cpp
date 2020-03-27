class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return 0;
        int r = matrix.size() - 1,c = 0;
        while(r >= 0 and c < matrix[0].size()){
            if(target == matrix[r][c]) return 1;
            if(target < matrix[r][c]) r--;
            else c++;
        }
        return 0;
    }
};
