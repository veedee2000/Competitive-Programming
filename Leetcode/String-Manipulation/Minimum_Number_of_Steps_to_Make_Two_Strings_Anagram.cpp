class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        unordered_map<char,int>mp1,mp2;
        for(auto x:s) mp1[x]++;
        for(auto x:t) mp2[x]++;
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        for(auto x:alpha) ans += abs(mp1[x] - mp2[x]);
        return ans / 2 + ans % 2;
    }
};
