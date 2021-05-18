class Solution{
    public:
    int longestKSubstr(string s, int k) {
        int n = s.size(), start = 0, ans = -1, unique = 0;
        vector<int>freq(26, 0);
        for(int end = 0;end < n;end++){
            if(freq[s[end] - 'a']++ == 0) unique++;
            while(unique > k){
                if(freq[s[start] - 'a']-- == 1) unique--;
                start++;
            } 
            if(unique == k) ans = max(ans, end - start + 1);
        }
        return ans;
    }
};
