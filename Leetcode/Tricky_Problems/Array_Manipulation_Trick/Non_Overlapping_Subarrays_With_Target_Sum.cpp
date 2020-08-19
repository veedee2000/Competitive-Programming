class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        int n = nums.size(), prefix = 0;
        vector<int>right(n);
        for(int i = n - 1;i >= 0;i--){
            mp[prefix] = i;
            prefix += nums[i];
            if(mp.count(prefix - target)) right[i] = min((i + 1 == n ? n + 1 : right[i + 1]), mp[prefix - target] - i + 1);
            else right[i] = i + 1 == n ? n + 1 : right[i + 1];
        }
        mp.clear();
        prefix = 0;
        int ans = n + 1;
        int leftMin = n + 1;
        for(int i = 0;i < n - 1;i++){
            mp[prefix] = i;
            prefix += nums[i];
            if(mp.count(prefix - target)){
                leftMin = min(leftMin, i - mp[prefix - target] + 1);
                ans = min(ans, leftMin + right[i + 1]);
            }
        }
        return ans > n ? -1 : ans;
    }
};
