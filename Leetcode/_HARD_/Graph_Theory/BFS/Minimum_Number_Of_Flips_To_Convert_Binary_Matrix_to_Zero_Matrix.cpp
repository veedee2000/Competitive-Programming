class Solution {
public:
    const int INF = 1e7;
    int m,n;
    vector<int>dr,dc;
    int minFlips(vector<vector<int>>& mat) {
        m = mat.size(),n = mat[0].size();
        dr = {0,0,-1,1},dc = {-1,1,0,0};
        unordered_set<int>s;
        int hash = cal(mat),ans = 0;
        queue<int>q;
        q.push(hash);
        s.insert(hash);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                hash = q.front();
                int newHash;
                q.pop();
                if(hash == 0) return ans;
                for(int i = 0;i < m;i++){
                    for(int j = 0;j < n;j++){
                        newHash = hash;
                        newHash ^= 1 << (i * n + j);
                        for(int rc = 0;rc < 4;rc++){
                            int x = i + dr[rc],y = j + dc[rc];
                            if(x >= 0 and x < m and y >= 0 and y < n){
                                newHash ^= 1 << (x * n + y);
                            }
                        }
                        if(!s.count(newHash)) q.push(newHash),s.insert(newHash);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
    
    int cal(vector<vector<int>>&mat){
        int hash = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(mat[i][j]) hash |= 1 << (i * n + j);
            }
        }
        return hash;
    }
};
