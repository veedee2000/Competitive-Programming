class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>hashReq(26,0),hash(26,0),ans;
        int n = s.size(),m = p.size();
        for(auto x:p){
            hashReq[x - 'a']++;
        }
        for(int i = 0;i < n;i++){
            hash[s[i] - 'a']++;
            if(i < p.size() - 1) continue;
            if(hash == hashReq) ans.push_back(i - m + 1);
            hash[s[i - m + 1] - 'a']--;
        }
        return ans;
    }
};
