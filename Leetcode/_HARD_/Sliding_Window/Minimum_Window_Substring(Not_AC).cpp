// Overall number of operations : 2 * (122 - 65) * sizeof(s)
// Time Complexity : O(n)
// Verdict - TLE

class Solution {
public:
    string minWindow(string s, string t) {
        cout<<s.size()<<" "<<t.size();
        return "";
        unordered_map<int,unordered_map<int,int>>mp;
        for(int i = 65;i <= 122;i++){
            mp[0][i] = (int(s[0]) == i) ? 1 : 0;
        }
        for(int i = 1;i < s.size();i++){
            for(int j = 65;j <= 122;j++){
                mp[i][j] = mp[i - 1][j];
            }
            mp[i][int(s[i])]++;
        }
        int count[130];
        memset(count,0,sizeof(count));
        for(auto x:t){
            count[int(x)]++;
        }
        int l = 0,r = 0,ans=INT_MAX,ans_l,ans_r;
        bool val = 0;
        if(t.size() == 1){
            for(auto x:s) if(x == t[0]) return string(1,x);
            return "";
        }
        while(r < s.size()){
            bool c = 1;
            for(int i = 65;i <= 122;i++){
                c &= (mp[r][i] - (l > 0 ? mp[l - 1][i] : 0) >= count[i]);
            }
            if(c and r - l + 1 < ans){
                ans = r - l + 1;
                ans_l = l;
                ans_r = r;
                ++l;
                val = 1;
            }
            else if(c){
                ++l;
                val = 1;
            }
            else ++r;
        }
        if(!val) return "";
        else return s.substr(ans_l,ans_r - ans_l + 1);
    }
};
