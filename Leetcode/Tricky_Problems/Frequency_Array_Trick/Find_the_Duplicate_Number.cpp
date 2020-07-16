// O(n) changing array allowed

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(nums[nums[i] % n] > n) return nums[i] % n;
            nums[nums[i] % n] += n;
        }
        return 0;
    }
};
