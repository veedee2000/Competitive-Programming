class NumArray {
public:
    vector<int>nums1;
    NumArray(vector<int>& nums) {
        nums1.resize(nums.size());
        if(!nums.size()) return;
        nums1[0] = nums[0];
        for(int i = 1;i < nums.size();i++){
            nums1[i] = nums[i] + nums1[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return (i == 0 ? nums1[j] : nums1[j] - nums1[i - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
