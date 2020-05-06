class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int maxCount = 0;
        for(auto x:tasks) { mp[x]++; maxCount = max(maxCount,mp[x]); }
        int ans = (maxCount - 1) * (n + 1);
        for(auto x:mp) if(x.second == maxCount) ans++;
        return max((int) tasks.size(), ans);
    }
};
