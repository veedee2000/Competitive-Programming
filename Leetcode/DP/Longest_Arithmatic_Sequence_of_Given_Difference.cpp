class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>mp;
        int ans = 1;
        mp[arr[0]] = 1;
        for(int i = 1;i < arr.size();i++){
            mp[arr[i]] = 1 + mp[arr[i] - difference];
            ans = max(ans,mp[arr[i]]);
        }
        return ans;
    }
};
