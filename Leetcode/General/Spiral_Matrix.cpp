class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(!matrix.size()) return {};
        int m = matrix.size(),n = matrix[0].size(),i = 0,j = 0,imax = m - 1,jmax = n - 1,imin = 0,jmin = 0;
        vector<int>ans;
        int c = 0;
        while(c < m * n){
            while(j <= jmax){
                ans.push_back(matrix[i][j]);
                j++;
                c++;
            }
            if(c == m * n) break;
            j--;
            imin++;
            i = imin;
            
            while(i <= imax){
                ans.push_back(matrix[i][j]);
                i++;
                c++;
            }
            if(c == m * n) break;
            i--;
            jmax--;
            j = jmax;
            
            while(j >= jmin){
                ans.push_back(matrix[i][j]);
                j--;
                c++;
            }
            if(c == m * n) break;
            j++;
            imax--;
            i = imax;
            
            while(i >= imin){
                ans.push_back(matrix[i][j]);
                i--;
                c++;
            }
            if(c == m * n) break;
            i++;
            jmin++;
            j = jmin;
        }
        return ans;
    }
};
