class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int l = 0, r = n - k - 1, m;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(x - nums[m] <= nums[m + k] - x) r = m - 1;
            else l = m + 1;
        }
        return vector<int>(nums.begin() + l, nums.begin() + l + k);
    }
}; 
