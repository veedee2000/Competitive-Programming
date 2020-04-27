class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int>path;
        f(n,k,path);
        return ans;
    }
    
    void f(int i,int k,vector<int>& path){
        if(k == 0) {ans.push_back(path); return;}
        if(i < 1) return;
        f(i - 1,k,path);
        path.push_back(i);
        f(i - 1,k - 1,path);
        path.pop_back();
    }
};
