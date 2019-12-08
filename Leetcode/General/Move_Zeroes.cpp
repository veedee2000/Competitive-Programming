class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 1;i < nums.size();i++){
            for(int j = 1;j < nums.size();j++){
                if(nums[j - 1] == 0) swap(nums[j-1],nums[j]);
            }
        }
    }
};
