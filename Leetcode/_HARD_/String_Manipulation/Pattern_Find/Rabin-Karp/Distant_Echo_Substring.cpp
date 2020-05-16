class Solution {
public:
    const int mod = 1e9 + 7;
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        int ans = 0;
        unordered_set<int>s;
        for(int i = 1;i < n;i++){
            long leftHash = 0,rightHash = 0,helper = 1;
            int l = i - 1,r = i;
            while(l >= 0 and r < n){
                leftHash = (leftHash + ((text[l--] - 'a' + 1) * helper) % mod) % mod;
                rightHash = ((rightHash * 27) % mod + (text[r++] - 'a' + 1)) % mod;
                helper = (helper * 27) % mod;
                if(leftHash == rightHash and !s.count(leftHash)){
                    s.insert(leftHash);
                    ans++;
                }
            }
        }
        return ans;
    }
};
