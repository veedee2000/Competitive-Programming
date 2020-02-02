class Solution {
public:
    string reorganizeString(string S) {
        auto comp = [](pair<char,int> a,pair<char,int> b){
            return (a.second < b.second);
        };
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(comp)>q(comp);
        unordered_map<char,int>mp;
        for(auto x:S) mp[x]++;
        for(auto x:mp){
            q.push({x.first,x.second});
        }
        string ans = "";
        pair<int,int>a = q.top();
        q.pop();
        a.second += 1000;
        q.push(a);
        while(!q.empty()){
            pair<int,int>curr = q.top();
            q.pop();
            ans.push_back(curr.first);
            if(!q.empty()){
                pair<char,int>topNow = q.top();
                q.pop();
                topNow.second += 1000;
                q.push(topNow);
            }
            if(curr.second - 1000 > 1) q.push({curr.first,curr.second - 1001});
        }
        if(ans.size() == 1) return ans;
        cout<<ans;
        for(int i = 1;i < ans.size();i++){
            if(ans[i] == ans[i - 1]) return "";
        }
        return ans;
    }
};
