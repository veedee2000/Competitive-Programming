class Solution {
    
    bool binSearch(vector<int>& nums,int val){
        int l = 0,r = nums.size() - 1,m;
        while(l <= r){
            m = l + (r - l) / 2;
            if(nums[m] == val) {nums.erase(nums.begin() + m); return 1;}
            if(nums[m] < val) l = m + 1;
            else r = m - 1;
        }
        return 0;
    }
    
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        if(nums1.size() < nums2.size()) swap(nums1,nums2);
        sort(nums2.begin(),nums2.end());
        for(auto x:nums1){
            if(binSearch(nums2,x)) ans.push_back(x);
        }
        return ans;
    }
};
