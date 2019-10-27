class Solution {
public:
    bool ans = 0,b[510000];
    int n;
    bool canJump(vector<int>& nums) {
        n = nums.size();
        memset(b,0,sizeof(b));
        dfs(0,nums);
        return ans;
    }
    
    void dfs(int i, vector<int>& nums){ 
        b[i] = 1;
        if(i >= n-1) {ans = true; return;}
        for(int j = 1;j <= nums[i];j++){
            if(!b[i + j]) dfs(i + j, nums);
        }
    }
};
