class Solution {
    
    struct comp{
        bool operator()(pair<char,int>a,pair<char,int>b){
            return a.second < b.second;
        }
    };
    
    const int INF = 1000;
    
public:
    string reorganizeString(string S){
        if(S == "") return "";
        unordered_map<char,int>mp;
        for(auto x:S) mp[x]++;
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq;
        for(auto x:mp){
            pq.push(x);
        }
        string ans;
        while(!pq.empty()){
            pair<char,int>top = pq.top();
            pq.pop();
            ans.push_back(top.first);
            if(pq.empty()){
                if(top.second == 1) break;
                else return "";
            }
            pair<char,int>secondTop = pq.top();
            pq.pop();
            ans.push_back(secondTop.first);
            if(--top.second) pq.push(top);
            if(--secondTop.second) pq.push(secondTop);
        }
        return ans;
    }
};
