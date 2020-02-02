#define MAX 11000

class Solution {
    struct comp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            return (a.second < b.second);
        }
    };
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int>ans;
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>q;
        for(auto x:barcodes) mp[x]++;
        for(auto x:mp) q.push({x.first,x.second});
        pair<int,int>a = q.top();
        q.pop();
        a.second += MAX;
        q.push(a);
        while(!q.empty()){
            pair<int,int>curr = q.top();
            q.pop();
            ans.push_back(curr.first);
            if(!q.empty()){
                pair<int,int>topNow = q.top();
                q.pop();
                topNow.second += MAX;
                q.push(topNow);
            }
            if(curr.second - MAX > 1) q.push({curr.first,curr.second - MAX - 1});
        }
        return ans;
    }
};
