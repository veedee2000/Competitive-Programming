class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans(strs.size());
        unordered_map<int,string>mp;
        vector<pair<string,int>>v;
        for(int i = 0;i < strs.size();i++){
            mp[i] = strs[i];
            v.push_back({strs[i],i});
        }
        for(auto &x:v){
            sort(x.first.begin(),x.first.end());
        }
        sort(v.begin(),v.end(),comp);
        string now = v[0].first;
        int index = 0;
        ans[0].push_back(mp[v[0].second]);
        for(int i = 1;i < v.size();i++){
            if(now != v[i].first) ++index,now = v[i].first;
            ans[index].push_back(mp[v[i].second]);
        }
        ans.resize(index + 1);
        return ans;
    }
    
    static bool comp(pair<string,int>&a,pair<string,int>&b){
        string a1 = a.first,b1 = b.first;
        return (a1 < b1);
    }
};
