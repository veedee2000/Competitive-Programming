class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(),count = 1;
        for(int i = n - 2;i >= 0;i--){
            if(nums[i] >= count) count = 1;
            else count++;
        }
        return (count == 1);
    }
};
