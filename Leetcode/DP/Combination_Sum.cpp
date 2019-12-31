class Solution {
public:
    vector<vector<int>>ans;
    vector<int>candidates;
    int n;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this -> candidates = candidates;
        n = candidates.size();
        f(target,0,{});
        return ans;
    }
    
    void f(int i,int x,vector<int>v){
        if(i < 0 or x > candidates.size() - 1) return;
        if(i == 0){
            ans.push_back(v);
            return;
        }
        for(int j = x;j < n;j++){
            v.push_back(candidates[j]);
            f(i - candidates[j],j,v);
            v.pop_back();
        }
    }
};
