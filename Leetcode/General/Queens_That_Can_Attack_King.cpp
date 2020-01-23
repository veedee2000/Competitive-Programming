class Solution {
public:
    vector<vector<int>>ans;
    unordered_map<int,unordered_map<int,int>>mp;
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        for(auto x:queens){
            mp[x[0]][x[1]] = 1;
        }
        int kx = king[0];
        int ky = king[1];
        traverse(kx + 1,ky,1,0);
        traverse(kx - 1,ky,-1,0);
        traverse(kx,ky + 1,0,1);
        traverse(kx,ky - 1,0,-1);
        traverse(kx + 1,ky + 1,1,1);
        traverse(kx + 1,ky - 1,1,-1);
        traverse(kx - 1,ky + 1,-1,1);
        traverse(kx - 1,ky - 1,-1,-1);
        return ans;
    }
    
    void traverse(int i,int j,int r,int c){
        if(i < 0 or j < 0 or i >= 8 or j >= 8) return;
        if(mp[i][j]){
            ans.push_back({i,j});
            return;
        }
        traverse(i + r,j + c,r,c);
    }
};
