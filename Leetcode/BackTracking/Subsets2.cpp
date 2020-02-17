class Solution {
public:
    unordered_map<string,int>mp;
    vector<vector<int>>ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        f(0,nums,{},"");
        return ans;
    }
    
    void f(int i,vector<int>nums,vector<int>v,string s){
        if(i == nums.size()){
            sort(s.begin(),s.end());
            if(!mp.count(s)) ans.push_back(v),mp[s] = 1;
            return;
        }
        f(i + 1,nums,v,s);
        v.push_back(nums[i]);
        f(i + 1,nums,v,s + to_string(nums[i]) + ",");
    }
};
