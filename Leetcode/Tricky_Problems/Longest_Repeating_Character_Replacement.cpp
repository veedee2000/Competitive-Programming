class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), maxc = 0, start = 0;
        vector<int>freq(26, 0);
        for(int end = 0;end < s.size();end++){
            maxc = max(maxc, ++freq[s[end] - 'A']);
            if(end - start + 1 - maxc > k) freq[s[start++] - 'A']--;
        }
        return n - start;
    }
};
