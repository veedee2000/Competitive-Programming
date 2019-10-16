class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(auto x:arr) mp[x]++;
        set<int>s;
        for(auto x:mp){
            if(s.count(x.second) == 0) s.insert(x.second);
            else return false;
        }
        return true;
    }
};
