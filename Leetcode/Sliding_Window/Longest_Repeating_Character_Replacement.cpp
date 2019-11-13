class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0,ans = 0,count=0;
        unordered_map<char,int>mp;
        for(int end = 0;end < s.size();end++){
            mp[s[end]]++;
            count = max(count, mp[s[end]]);
            while(end - start - count + 1 > k){
                mp[s[start]]--;
                start++;
                for(int i = 0;i < 26;i++){
                    count = max(count, mp[(char)('A' + i)]);
                }
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};
