 class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest = INT_MAX;
        for(int i = 0;i < nums.size() - 2;i++){
            int l = i + 1, r = nums.size() - 1, sum;
            while(l < r){
                sum = nums[i] + nums[l] + nums[r];
                if(closest == INT_MAX or abs(sum - target) < abs(closest - target)) closest = sum;
                if(sum < target) l++;
                else r--;
                if(closest == target) return target;
            }
        }
        return closest;
    }
};
