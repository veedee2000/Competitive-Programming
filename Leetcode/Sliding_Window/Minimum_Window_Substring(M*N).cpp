class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "",curr = "";
        unordered_map<char,int>mp;
        for(auto x:t) mp[x]++;
        int i = 0,j = 0;
        while(j < s.size()){
            curr.push_back(s[j]);
            if(mp.count(s[j])) mp[s[j]]--;
            bool c = 1;
            for(auto x:mp) if(x.second > 0) {c = 0; break;}
            if(c){
                if(ans == "" or curr.size() < ans.size()) ans = curr;
                while(i <= j and (!mp.count(s[i]) or mp[s[i]] + 1 < 1)){
                    curr.erase(0,1);
                    if(ans == "" or curr.size() < ans.size()) ans = curr;
                    if(mp.count(s[i])) mp[s[i]]++;
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};
