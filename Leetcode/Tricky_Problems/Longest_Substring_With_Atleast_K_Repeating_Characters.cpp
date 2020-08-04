class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size(), ans = 0;
        for(int u = 1;u <= 26;u++){
            int left = 0, right = 0, unique = 0, kOrMore = 0;
            vector<int>count(26, 0);
            while(right < n){
                if(unique <= u){
                    int c = s[right] - 'a';
                    count[c]++;
                    if(count[c] == 1) ++unique;
                    if(count[c] == k) ++kOrMore;
                    right++;
                }
                else{
                    int c = s[left] - 'a';
                    count[c]--;
                    if(count[c] == k - 1) --kOrMore;
                    if(count[c] == 0) --unique;
                    left++;
                }
                if(u == unique and unique == kOrMore) ans = max(ans, right - left);
            }
        }
        return ans;
    }
};
