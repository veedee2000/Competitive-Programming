const int MAX = 10000000;

class Solution {
    
    struct comp{
        bool operator ()(pair<int,int>&a,pair<int,int>&b){
            return (a.second > b.second);
        }
    };
    
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        vector<vector<int>>dist(n,vector<int>(n,MAX));
        unordered_map<int,unordered_map<int,int>>mp;
        for(int i = 0;i < n;i++){
            dist[i][i] = 0;
        }
        for(auto x:edges){
            mp[x[0]][x[1]] = x[2];
            mp[x[1]][x[0]] = x[2];
        }
        for(int i = 0;i < n;i++){
            pq.push({i,0});
            vector<bool>vis(n,0);
            while(!pq.empty()){
                pair<int,int>curr = pq.top();
                pq.pop();
                int index = curr.first,minVal = curr.second;
                vis[index] = 1;
                for(auto y:mp[index]){
                    if(vis[y.first]) continue;
                    int newDist = dist[i][index] + y.second;
                    if(newDist < dist[i][y.first]){
                        dist[i][y.first] = newDist;
                        pq.push({y.first,newDist});
                    }
                }
            }
        }
        int ans,val,minVal = INT_MAX;
        for(int i = 0;i < n;i++){
            val = 0;
            for(auto x:dist[i]){
                if(x <= distanceThreshold) val++;
            }
            cout<<endl;
            if(val <= minVal) ans = i,minVal = val;
        }
        return ans;
    }
};
