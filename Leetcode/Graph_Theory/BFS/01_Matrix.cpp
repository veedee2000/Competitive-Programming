class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>>ans(matrix.size(),vector<int>(matrix[0].size(),0));
        queue<int>q;
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    int val = i * matrix[0].size() + j;
                    q.push(val);
                }
            }
        }
        
        vector<int>dr = {-1,1,0,0},dc = {0,0,-1,1};
        int dist = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int it = 0;it < sz;it++){
                int curr = q.front();
                q.pop();
                int x = curr / matrix[0].size(),y = curr % matrix[0].size();
                if(matrix[x][y] == -1) ans[x][y] = dist;
                for(int rc = 0;rc < 4;rc++){
                    int x1 = x + dr[rc],y1 = y + dc[rc];
                    if(x1 >= 0 and y1 >= 0 and x1 < matrix.size() and y1 < matrix[0].size() and matrix[x1][y1] == 1){
                        q.push(x1 * matrix[0].size() + y1),matrix[x1][y1] = -1;
                    }
                }
            }
            ++dist;
        }
        return ans;
    }
};
