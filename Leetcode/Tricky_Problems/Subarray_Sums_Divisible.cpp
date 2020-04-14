class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        vector<int>v(k,0);
        int pre = 0,ans = 0,mod;
        for(auto x:A){
            pre += x;
            if(pre % k == 0) ans++;
            mod = (pre >= 0) ? pre % k : (k - abs(pre) % k) % k;
            ans += v[mod];
            v[mod]++;
        }
        return ans;
    }
};
