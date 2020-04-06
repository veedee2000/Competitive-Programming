class Solution {
public:
    vector<vector<int>>ans;
    vector<int>candidates;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this -> candidates = candidates;
        f(0,target,{});
        return ans;
    }
    
    void f(int i,int target,vector<int>path){
        if(target == 0){
            ans.push_back(path);
            return;
        }
        for(int j = i;j < candidates.size() and candidates[j] <= target;j++){
            if(j == i or candidates[j - 1] != candidates[j]){
                path.push_back(candidates[j]);
                f(j + 1,target - candidates[j],path);
                path.pop_back();
            }
        }
    }
};
