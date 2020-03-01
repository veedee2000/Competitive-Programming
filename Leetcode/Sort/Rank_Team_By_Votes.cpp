class Solution {
    
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char,unordered_map<int,int>>mp;
        int sz = votes[0].size();
        for(auto x:votes){
            for(int i = 0;i < x.size();i++){
                mp[x[i]][i]++;
            }
        }
        vector<pair<char,vector<int>>>v;
        for(auto x:mp){
            vector<int>sub(sz,0);
            for(int i = 0;i < sz;i++){
                if(mp[x.first].count(i)) sub[i] = mp[x.first][i];
            }
            v.push_back({x.first,sub});
        }
        sort(v.begin(),v.end(),comp);
        string ans;
        for(auto x:v) ans.push_back(x.first);
        return ans;
    }
    
    bool static comp(pair<char,vector<int>>&a,pair<char,vector<int>>&b){
        vector<int>av = a.second, bv = b.second;
        for(int i = 0;i < av.size();i++){
            if(av[i] != bv[i]) return (av[i] > bv[i]);
        }
        return a.first < b.first;
    }
};
