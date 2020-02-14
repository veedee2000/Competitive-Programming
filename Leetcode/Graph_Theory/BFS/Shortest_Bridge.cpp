class Solution {
public:
    vector<int>dr,dc;
    queue<int>q;
    int shortestBridge(vector<vector<int>>& A) {
        dr = {0,0,-1,1},dc = {1,-1,0,0};
        int b = 1;
        for(int i = 0;i < A.size();i++){
            for(int j = 0;j < A[0].size();j++){
                if(A[i][j] == 1) island(i,j,A,b),b = -b;
                // cout<<A[i][j]<<" ";
            }
            // cout<<endl;
        }  
        
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int it = 0;it < sz;it++){
                int curr = q.front();
                q.pop();
                int i = curr / A[0].size(),j = curr % A[0].size();
                A[i][j] = -1;
                for(int rc = 0;rc < 4;rc++){
                    int x = i + dr[rc],y = j + dc[rc];
                    if(x >= 0 and y >= 0 and x < A.size() and y < A[0].size() and A[x][y] != -1){
                        if(A[x][y] == 0) q.push(x * A[0].size() + y);
                        else if(A[x][y] == -2) return ans;
                        A[x][y] = -1;
                    }
                }
            }
            ++ans;
        }
        
        return ans;
        
    }
                                
    void island(int i,int j,vector<vector<int>>& A,int b){
        if(i < 0 or j < 0 or i >= A.size() or j >= A[0].size()) return;
        if(A[i][j] == 0 or A[i][j] == -2 or A[i][j] == -1) return;
        if(b == 1) q.push(i * A[0].size() + j),A[i][j] = -1;
        else A[i][j] = -2;
        for(int rc = 0;rc < 4;rc++){
            int x = i + dr[rc],y = j + dc[rc];
            island(x,y,A,b);
        }
    }
};
