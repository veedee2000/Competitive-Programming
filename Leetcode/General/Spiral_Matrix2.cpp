class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));
        int i = 0,j = 0,imax = n - 1,jmax = n - 1,imin = 0,jmin = 0;
        int c = 0;
        while(c < n * n){
            while(j <= jmax){
                matrix[i][j] = ++c;
                j++;
            }
            if(c == n * n) break;
            j--;
            imin++;
            i = imin;
            
            while(i <= imax){
                matrix[i][j] = ++c;
                i++;
            }
            if(c == n * n) break;
            i--;
            jmax--;
            j = jmax;
            
            while(j >= jmin){
                matrix[i][j] = ++c;
                j--;
            }
            if(c == n * n) break;
            j++;
            imax--;
            i = imax;
            
            while(i >= imin){
                matrix[i][j] = ++c;
                i--;
            }
            if(c == n * n) break;
            i++;
            jmin++;
            j = jmin;
        }
        return matrix;
    }
};
