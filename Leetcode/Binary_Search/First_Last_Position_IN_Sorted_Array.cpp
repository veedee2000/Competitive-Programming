class Solution {
    vector<int>nums;
    int binSearch(int l,int r,int target,bool c){
        int val = -1;
        while(l <= r){
            if(l == r){
                if(nums[l] == target) val = l;
                return val;
            } 
            int m = l + (r - l) / 2;
            if(nums[m] == target){
                val = m;
                if(!c) r = m - 1;
                else l = m + 1;
            }
            else if(nums[m] < target){
                l = m + 1;
            }
            else r = m - 1;
        }
        return val;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        this -> nums = nums;
        int first = binSearch(0,nums.size() - 1,target,0);
        int second = binSearch(0,nums.size() - 1,target,1);
        return {first,second};
    }
};
