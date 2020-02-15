class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
        f(0,{},nums);
        return ans;
    }
    
    void f(int hash,vector<int>v,vector<int>& nums){
        if(v.size() == nums.size()){
            ans.push_back(v);
            return;
        }
        
        for(int i = 0;i < nums.size();i++){
            if((hash & (1 << i)) == 0){
                v.push_back(nums[i]);
                f(hash | (1 << i),v,nums);
                v.pop_back();
            }
        }
    }
    
};
