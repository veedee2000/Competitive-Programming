class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string, int>mp;
        for(auto x:strs){
            string ans = "";
            for(int i=0;i<x.size();i++){
                ans += x[i];
                mp[ans]++;
            }
        }
        int value = 1;
        string ans;
        for(auto x:mp){
            if(x.second >= value){
                if(x.first.size() > ans.size()) {value = x.second; ans = x.first;}
            }
        }
        
        if(value < strs.size()) return "";
        else return ans;
    }
};
