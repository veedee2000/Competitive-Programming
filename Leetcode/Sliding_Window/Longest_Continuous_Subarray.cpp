class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<vector<int>>greater,lesser;
        int start = 0,end = 0,n = nums.size();
        int ans = 0,minVal,maxVal,maxDiff;
        while(end < n){
            if(!greater.size()) greater.push_back({nums[end],end}),lesser.push_back({nums[end],end});
            else{
                while(greater.size() and greater.front()[0] < nums[end]) greater.pop_front();
                greater.push_front({nums[end],end});
                while(lesser.size() and lesser.front()[0] > nums[end]) lesser.pop_front();
                lesser.push_front({nums[end],end});
                while(greater.back()[0] - lesser.back()[0] > limit){
                    if(greater.back()[1] == start) greater.pop_back();
                    if(lesser.back()[1] == start) lesser.pop_back();
                    start++;
                } 
            }
            ans = max(ans,end - start + 1);
            end++;
        }
        return ans;
    }
};
