class Solution {
    
    unordered_map<string, vector<string>>mp;
    
    void dfs(string& s, vector<string>& ans){
        string next;
        int i;
        while(mp[s].size()){
            i = mp[s].size() - 1;
            next = mp[s][i];
            mp[s].pop_back();
            dfs(next, ans);
        }
        ans.push_back(s);
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets){
        for(auto x:tickets){
            mp[x[0]].push_back(x[1]);
        }
        for(auto &x:mp){
            sort(x.second.begin(), x.second.end(), greater<string>());
        }
        vector<string>ans;
        string start = "JFK";
        dfs(start, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
