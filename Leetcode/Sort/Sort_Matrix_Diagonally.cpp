class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(),count = m + n - 1;
        int iS = m - 1,jS = 0,index;
        while(count--){
            vector<int>v;
            int i = iS,j = jS;
            if(j == 0){
                while(i <= m - 1 and j <= n - 1){
                    v.push_back(mat[i][j]);
                    i++,j++;
                }
                sort(v.begin(),v.end());
                i = iS,j = jS;
                index = 0;
                while(i <= m - 1 and j <= n - 1){
                    mat[i][j] = v[index++];
                    i++,j++;
                }
                if(iS > 0) iS--;
                else jS++;
            }
            else{
                while(i <= m - 1 and j <= n - 1){
                    v.push_back(mat[i][j]);
                    i++,j++;
                }
                sort(v.begin(),v.end());
                i = iS,j = jS;
                index = 0;
                while(i <= m - 1 and j <= n - 1){
                    mat[i][j] = v[index++];
                    i++,j++;
                }
                jS++;
            }
        }
        
        return mat;
    }
};
