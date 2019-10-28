class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const auto nums_size = nums.size();
        int index = 0;
        for (int i=nums_size-1; i>0; --i) {
            if (nums[i]>nums[i-1]) {
                int j;
                for (j=nums_size-1; j>=i; --j) {
                    if (nums[j]>nums[i-1]) {
                        break;
                    }
                }
                swap(nums[i-1],nums[j]);
                index=i;
                break;
            }
        }
        int len = nums_size-index;
        for (int i=0; i<len/2; ++i){
            swap(nums[i+index],nums[nums_size-1-i]);
        }
    }
};
