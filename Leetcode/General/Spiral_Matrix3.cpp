class Solution {
public:
    int R,C;
    vector<vector<int>>ans;
    vector<vector<int>>dir;
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        this -> R = R;
        this -> C = C;
        dir.push_back({0,1});
        dir.push_back({1,0});
        dir.push_back({0,-1});
        dir.push_back({-1,0});
        ans.push_back({r0,c0});
        dfs(r0,c0 + 1,0,1,1,1);
        return ans;
    }
    
    void dfs(int r,int c,int d,int see,int countNow,int countMax){
        if(ans.size() == R * C) return;
        if(r < 0 or r > R - 1 or c < 0 or c > C - 1) {}
        else ans.push_back({r,c});
        if(countNow == countMax){
            d = (d + 1) % 4;
            if(see == 2){
                see = 0;
                ++countMax;
            }
            ++see;
            countNow = 1;
        }
        else ++countNow;
        r += dir[d][0];
        c += dir[d][1];
        dfs(r,c,d,see,countNow,countMax);
    }
};
