class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>path = {};
        f(nums,path);
        return ans;
    }
    
    void f(vector<int>& nums,vector<int>& path){
        if(!nums.size()) { ans.push_back(path); return; }
        for(int i = 0;i < nums.size();i++){
            int val = nums[i];
            path.push_back(val);
            nums.erase(nums.begin() + i);
            f(nums,path);
            nums.insert(nums.begin() + i,val);
            path.pop_back();
        }
    }
};
